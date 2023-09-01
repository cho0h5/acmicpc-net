#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m, k;
char board[1000][1001];
int vis[1000][1000][11];
queue<tuple<int, int, int> > q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void printb() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void printv() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%2d ", vis[i][j][0]);
        }
        cout << "\t";
        for (int j = 0; j < m; j++) {
            printf("%2d ", vis[i][j][1]);
        }
        cout << "\t";
        for (int j = 0; j < m; j++) {
            printf("%2d ", vis[i][j][2]);
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    q.push({0, 0, 0});
    vis[0][0][0] = 1;

    // printb();

    while (!q.empty()) {
        int x, y, s;
        tie(x, y, s) = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (board[nx][ny] == '0') {
                int ns = s;

                if (vis[nx][ny][ns] > vis[x][y][s] + 1) {
                    vis[nx][ny][ns] = vis[x][y][s] + 1;
                    q.push({nx, ny, ns});
                    continue;
                }

                if (vis[nx][ny][ns] != 0) continue;

                vis[nx][ny][ns] = vis[x][y][s] + 1;
                q.push({nx, ny, ns});
            } else {
                int ns = s + 1;
                if (ns > k) continue;
                if (vis[nx][ny][ns] != 0) continue;

                if (vis[x][y][s] % 2 == 1) vis[nx][ny][ns] = vis[x][y][s] + 1;
                else vis[nx][ny][ns] = vis[x][y][s] + 2;
                q.push({nx, ny, ns});
            }
        }
    }
    // printv();

    int mmin = 2147483647;
    for (int i = 0; i <= k; i++) {
        int r = vis[n - 1][m - 1][i];
        if (r != 00 && r < mmin) mmin = r;
    }
    if (mmin != 2147483647) cout << mmin << '\n';
    else cout << "-1\n";
}
