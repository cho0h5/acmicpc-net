#include <iostream>
#include <queue>

using namespace std;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int sx, sy;
int tx, ty;
int vis[300][300];
int tc;
int l;
queue<pair<int, int> > q;

void init() {
    while (!q.empty()) q.pop();
    cin >> l;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            vis[i][j] = -1;
        }
    }
    cin >> sx >> sy;
    cin >> tx >> ty;

    vis[sx][sy] = 0;
    q.push(make_pair(sx, sy));
}

int solution() {
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        if (cur.first == tx && cur.second == ty) return vis[cur.first][cur.second];

        for(int i = 0; i < 8; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            if (vis[nx][ny] != -1) continue;

            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return -1;
}

int main() {
    cin >> tc;
    while (tc--) {
        init();
        cout << solution() << '\n';
    }
}
