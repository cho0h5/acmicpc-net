#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int k;
int w, h;
int board[200][200];
int vis[200][200][31];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int dx2[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy2[] = {2, 1, -1, -2, -2, -1, 1, 2};

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
    cin >> k;
    cin >> w >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> board[i][j];
        }
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
            if (vis[nx][ny][nstate] != 0 || board[nx][ny] != 0) continue;

            vis[nx][ny][nstate] = vis[x][y][state] + 1;
            q.push({nx, ny, nstate});
        }

        for(int i = 0; i < 8; i++) {
            int nx = x + dx2[i];
            int ny = y + dy2[i];
            int nstate = state + 1;

            if (nx < 0 || nx >= h || ny < 0 || ny >= w || nstate > k) continue;
            if (vis[nx][ny][nstate] != 0 || board[nx][ny] != 0) continue;

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
    else cout << mmin - 1 << '\n';
}
