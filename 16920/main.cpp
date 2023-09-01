#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int> > q[9];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

char board[1000][1001];
int vis[1000][1000];
int s[9];

int h, w, p;

void printb() {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int empty() {
    for(int i = 0; i < p; i++) {
        if(!q[i].empty()) {
            return 0;
        }
    }
    return 1;
}

int main() {
    cin >> h >> w >> p;
    for (int i = 0; i < p; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < h; i++) {
        cin >> board[i];
        for (int j = 0; j < w; j++) {
            if ('1' <= board[i][j] && board[i][j] <= '9') {
                q[board[i][j] - '1'].push(make_pair(i, j));
            }
        }
    }
    
    printb();

    while (!empty()) {
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < s[i]; j++) {
                int s = q[i].size();
                for (int k = 0; k < s; k++) {
                    pair<int, int> cur = q[i].front(); q[i].pop();

                    for (int l = 0; l < 4; l++) {
                        int nx = cur.first + dx[l];
                        int ny = cur.second + dy[l];

                        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                        if (vis[nx][ny] != 0 || board[nx][ny] != '.') continue;

                        vis[nx][ny] = 1;
                        board[nx][ny] = i + '1';
                        q[i].push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    printb();
}
