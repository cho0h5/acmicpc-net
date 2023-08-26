#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int vis[500][500];
int board[500][500];
int mmax = 0;
int ccount = 0;
queue<pair<int, int> > q;
int h, w;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void search() {
    int area = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(vis[nx][ny] == 1 || board[nx][ny] == 0) continue;

            area++;
            vis[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
    if (mmax < area) mmax = area;
}

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) {
            if (vis[i][j] != 1 && board[i][j] == 1) {
                ccount++;
                vis[i][j] = 1;
                q.push(make_pair(i, j));
                search();
            }
        }
    }
    cout << ccount << '\n';
    cout << mmax << '\n';
}
