#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int k;
int w, h;
char board[2000][2001];
int vis[2000][2000][11];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

queue<tuple<int, int, int> > q;

void printv() {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << vis[i][j][0] << ' ';
        }
        cout << "  ";
        for(int j = 0; j < w; j++) {
            cout << vis[i][j][1] << ' ';
        }
        cout << "  ";
        for(int j = 0; j < w; j++) {
            cout << vis[i][j][2] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> h >> w;
    cin >> k;
    for(int i = 0; i < h; i++) {
        cin >> board[i];
    }
    q.push({0, 0, 0});
    vis[0][0][0] = 1;

    while (!q.empty()) {
        int x, y, state;
        tie(x, y, state) = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nstate = state;

            if (nx < 0 || nx >= h || ny < 0 || ny >= w || nstate > k) continue;
            if (board[nx][ny] != '0') {
                nstate++;
                if (nstate > k) continue;
                if (vis[nx][ny][nstate] != 0) continue;

                vis[nx][ny][nstate] = vis[x][y][state] + 1;
                q.push({nx, ny, nstate});
                continue;
            }
            if (vis[nx][ny][nstate] != 0 || board[nx][ny] != '0') continue;

            vis[nx][ny][nstate] = vis[x][y][state] + 1;
            q.push({nx, ny, nstate});
        }
    }
    // printv();

    int mmin = 2147483647;
    for(int i = 0; i <= k; i++) {
        int end = vis[h - 1][w - 1][i];
        if (end != 0 && end < mmin) mmin = end;
    }
    if (mmin == 2147483647) cout << "-1\n";
    else cout << mmin << '\n';
}
