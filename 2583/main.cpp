#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int board[100][100];
int vis[100][100];
int h, w, k;
queue<pair<int, int> > q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
vector<int> result;

void printm() {
    for(int i = h - 1; i >= 0; i--) {
        for(int j = 0; j < w; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void printv() {
    for(int i = h - 1; i >= 0; i--) {
        for(int j = 0; j < w; j++) {
            cout << board[i][j] << ' ';
        }
        cout << "  ";
        for(int j = 0; j < w; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> h >> w >> k;
    for(int i = 0; i < k; i++) {
        int sx, sy, ex, ey;
        cin >> sy >> sx >> ey >> ex;
        for(int j = sx; j < ex; j++) {
            for(int k = sy; k < ey; k++) {
                board[j][k] = 1;
            }
        }
        // printm();
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if (vis[i][j] == 0 && board[i][j] == 0) {
                vis[i][j] = 1;
                int area = 1;
                q.push(make_pair(i, j));

                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];

                        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                        if (vis[nx][ny] != 0 || board[nx][ny] != 0) continue;

                        area++;
                        vis[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
                // printv();
                result.push_back(area);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (auto e : result) {
        cout << e << ' ';
    }
    cout << '\n';
}
