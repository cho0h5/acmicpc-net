#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
queue<tuple<int, int, int> > q;
char board[1001][1001];
int vis[1000][1000];
int wis[1000][1000];
int n, m;

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
        cout << "  ";
        for(int j = 0; j < m; j++) {
            cout << wis[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }
    // printb();
    q.push(make_tuple(0, 0, 0));
    vis[0][0] = 1;
    // printv();
    while (!q.empty()) {
        tuple<int, int, int> cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            int state = get<2>(cur);

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (state == 0) {
                if (vis[nx][ny] != 0) continue;

                if (board[nx][ny] == '0') {
                    vis[nx][ny] = vis[get<0>(cur)][get<1>(cur)] + 1;
                    q.push(make_tuple(nx, ny, 0));
                } else {
                    wis[nx][ny] = vis[get<0>(cur)][get<1>(cur)] + 1;
                    q.push(make_tuple(nx, ny, 1));
                }
            } else {
                if (wis[nx][ny] != 0) continue;
                if (board[nx][ny] != '0') continue;

                wis[nx][ny] = wis[get<0>(cur)][get<1>(cur)] + 1;
                q.push(make_tuple(nx, ny, 1));
            }
        }
        // printv();
    }
    // printv();
    if (vis[n - 1][m - 1] == 0 && wis[n - 1][m - 1] == 0) cout << -1 << '\n';
    else if (wis[n - 1][m - 1] == 0) cout << vis[n - 1][m - 1] << '\n';
    else if (vis[n - 1][m - 1] == 0) cout << wis[n - 1][m - 1] << '\n';
    else cout << min(vis[n - 1][m - 1], wis[n - 1][m - 1]) << '\n';
}
