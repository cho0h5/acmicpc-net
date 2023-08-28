#include <iostream>
#include <queue>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
queue<pair<int, int> > q;
int board[100][100];
int vis[100][100];
int n;
int mmax = 0;

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            vis[i][j] = 0;
        }
    }
}

void printv() {
    cout << '\n';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int search(int level) {
    int result = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (board[i][j] > level && vis[i][j] == 0) {
                result++;
                vis[i][j] = result;
                q.push(make_pair(i, j));

                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    for(int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (vis[nx][ny] != 0 || board[nx][ny] <= level) continue;

                        vis[nx][ny] = result;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    // printv();
    return result;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] > mmax) mmax = board[i][j];
        }
    }

    int maxx = 0;
    for(int i = 0; i <= mmax; i++) {
        init();
        int result = search(i);
        if (maxx < result) maxx = result;
    }
    cout << maxx;
    cout << '\n';
}
