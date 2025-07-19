#include <iostream>
#include <vector>

using namespace std;

int n, m, d;

vector<int> board[15];
int archors[3];
int target[3];

int distance_my(const int x1, const int y1, const int x2, const int y2) {
    // printf("(%d, %d) (%d, %d)\n", x1, y1, x2, y2);
    return abs(x2 - x1) + abs(y2 - y1);
}

int sol() {
    // Copy board
    vector<int> board_copy[15];
    for (int i = 0; i < m; i++) {
        board_copy[i] = board[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // printf("turn: %d\n", i);

        for (int j = 0; j < 3; j++) {
            // Get nearest enemy
            target[j] = -1;
            int min_d = 9999;
            for (int k = 0; k < m; k++) {
                // printf("size: %ld ", board_copy[k].size());
//                if (board_copy[k].size()) {
//                    printf("(%d)\n", board_copy[k].back());
//                } else {
//                    printf("\n");
//                }
                if (board_copy[k].empty()) {
                    continue;
                }
                const int dis = distance_my(board_copy[k].back(), k, n - i, archors[j]);
                // printf("dis: %d\n", dis);
                if (dis > d) {
                    continue;
                }
                if (dis < min_d) {
                    target[j] = k;
                    min_d = dis;
                }
            }

            // printf("target[%d]: %d\n", j, target[j]);
        }

        for (int j = 0; j < 3; j++) {
            if (target[j] == -1) {
                continue;
            }

            if (j == 1) {
                if (target[0] == target[1]) {
                    continue;
                }
            } else if (j == 2) {
                if (target[0] == target[2] || target[1] == target[2]) {
                    continue;
                }
            }

            board_copy[target[j]].pop_back();
            cnt += 1;
        }
        for (int j = 0; j < m; j++) {
            if (board_copy[j].empty()) {
                continue;
            }

            if (board_copy[j].back() >= n - i - 1) {
                board_copy[j].pop_back();
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (x) {
                board[j].push_back(i);
            }
        }
    }

    int maximum = 0;
    for (archors[0] = 0; archors[0] < m; archors[0]++) {
        for (archors[1] = archors[0] + 1; archors[1] < m; archors[1]++) {
            for (archors[2] = archors[1] + 1; archors[2] < m; archors[2]++) {
                // printf("%d, %d, %d\n", archors[0], archors[1], archors[2]);
                int result = sol();
                // printf("result: %d\n\n", result);
                maximum = max(maximum, result);
            }
        }
    }

    printf("%d\n", maximum);

    return 0;
}
