#include <iostream>
#include <queue>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int board[100][100];
int vis[100][100];
int n;

queue<pair<int, int> > q;
queue<pair<int, int> > p;

void printb() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << "  ";
        for(int j = 0; j < n; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            vis[i][j] = 0;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    int c = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (board[i][j] == 1 && vis[i][j] == 0) {
                p.push(make_pair(i, j));
                vis[i][j] = c++;

                while (!p.empty()) {
                    pair<int, int> cur = p.front(); p.pop();

                    for(int i = 0; i < 4; i++) {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(vis[nx][ny] != 0 || board[nx][ny] != 1) continue;
                        vis[nx][ny] = vis[cur.first][cur.second];
                        p.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }

    int mmin = 2147483647;

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[nx][ny] != 0 && vis[cur.first][cur.second] != vis[nx][ny]) {
                int n1 = board[nx][ny];
                int n2 = board[cur.first][cur.second];
                if (n1 + n2 - 2 < mmin) mmin = n1 + n2 - 2;
                continue;
            }
            if(vis[nx][ny] != 0) continue;

            vis[nx][ny] = vis[cur.first][cur.second];
            board[nx][ny] = board[cur.first][cur.second] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    cout << mmin << '\n';
}
