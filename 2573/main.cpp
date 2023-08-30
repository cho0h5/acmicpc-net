#include <iostream>
#include <queue>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int board[300][300];
int vis[300][300];
int n, m;
queue<pair<int, int> > q;

void printb() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void printv() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void init() {
    while(!q.empty()) q.pop();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }
}

int count_ice() {
    init();
    int result = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (board[i][j] != 0 && vis[i][j] == 0) {
                q.push(make_pair(i, j));
                vis[i][j] = 1;
                result++;

                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();

                    for(int i = 0; i < 4; i++) {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] != 0 || board[nx][ny] == 0) continue;

                        vis[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    return result;
}

void disolve() {
    init();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (board[i][j] != 0 && vis[i][j] == 0) {
                vis[i][j] = 1;
                q.push(make_pair(i, j));

                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();

                    for(int i = 0; i < 4; i++) {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (board[nx][ny] == 0 && vis[nx][ny] != 1 && board[cur.first][cur.second] != 0) {
                            board[cur.first][cur.second]--;
                            continue;
                        }
                        if (vis[nx][ny] != 0 || board[nx][ny] == 0) continue;

                        vis[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int c = 0;
    int d;

    while((d = count_ice()) == 1) {
        disolve();
        c++;
    }

    if (d == 0 || d == 1) {
        cout << "0\n";
    } else {
        cout << c;
        cout << '\n';
    }
}
