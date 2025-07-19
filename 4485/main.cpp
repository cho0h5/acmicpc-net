#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n;
int board[125][125];
int vst[125][125];

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

int bfs() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.push({board[0][0], 0, 0});  // cost, x, y

    while (q.size()) {
        auto [cc, cx, cy] = q.top();
        q.pop();

        if (cx == n - 1 && cy == n - 1) {
            return cc;
        }

        for (int i = 0; i < 4; i++) {
            const int nx = cx + dx[i];
            const int ny = cy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                continue;
            }

            const int nc = cc + board[nx][ny];
            if (nc < vst[nx][ny]) {
                vst[nx][ny] = nc;
                q.push({nc, nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 1;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
                vst[i][j] = 2147483647;
            }
        }
        const int result = bfs();
        printf("Problem %d: %d\n", tc++, result);
    }
}
