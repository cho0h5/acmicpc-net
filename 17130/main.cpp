#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

int board[1000][1000];
int vst[1000][1000];
int x;
int y;
int maximum = -1;

const int dx[3] = {-1, 0, 1};
const int dy[3] = {1, 1, 1};

void bfs() {
    queue<tuple<int, int>> q;
    q.push({x, y});
    vst[x][y] = 0;

    while (q.size()) {
        auto [cx, cy] = q.front();
        const int cc = vst[cx][cy];
        q.pop();

        if (board[cx][cy] == 'O') {
            if (maximum < cc) {
                maximum = cc;
            }
        }

        for (int i = 0; i < 3; i++) {
            const int nx = cx + dx[i];
            const int ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (board[nx][ny] == '#') {
                continue;
            }

            const int nc = cc + (board[nx][ny] == 'C');

            if (vst[nx][ny] < nc) {
                vst[nx][ny] = nc;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'R') {
                x = i;
                y = j;
            } else {
                board[i][j] = c;
            }
        }
    }

    memset(vst, -1, sizeof(vst));
    bfs();

    printf("%d\n", maximum);
}
