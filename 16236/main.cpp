#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

int n;
int board[20][20];
set<array<int, 3>> fishes;   // x, y, size
int x, y;
int fish_time = 0;
int fish_size = 2;
int state = 0;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

int bfs(const array<int, 3> fish) {
    queue<tuple<int, int, int>> q;
    q.push({x, y, 0});
    vector<vector<int>> vst(n, vector(n, 0));

    while (q.size()) {
        auto [cx, cy, cc] = q.front();
        q.pop();
        if (vst[cx][cy]) {
            continue;
        }
        vst[cx][cy] = 1;

        if (cx == fish[0] && cy == fish[1]) {
            return cc;
        }

        for (int i = 0; i < 4; i++) {
            const int nx = cx + dx[i];
            const int ny = cy + dy[i];
            const int nc = cc + 1;

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                continue;
            }

            if (board[nx][ny] > fish_size) {
                continue;
            }

            q.push({nx, ny, nc});
        }
    }
    return 99999;
}

array<int, 3> find_target() {
    array<int, 3> target;
    target[0] = -1;
    target[1] = -1;
    target[2] = -1;
    int td = 99999;

    // printf("--------\n");
    for (auto &fish: fishes) {
        if (fish[2] >= fish_size) {
            continue;
        }

        const int distance = bfs(fish);
        // printf("cantidate: (%d, %d), %d - %d\n", fish[0], fish[1], fish[2], distance);

        if (distance < td ||
                (distance == td && fish[0] < fish[0]) ||
                (distance == td && fish[0] == fish[0] && fish[1] < fish[1])) {
            target = fish;
            td = distance;
        }
    }

    fishes.erase(target);

    target[2] = td;
    return target;
}

void sol() {
    while (1) {
        array<int, 3> target = find_target();

        if (target[0] == -1) {
            return;
        }

        x = target[0];
        y = target[1];
        fish_time += target[2];
        state += 1;
        if (fish_size == state) {
            fish_size += 1;
            state = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                board[i][j] = 0;
                x = i;
                y = j;
            } else if (board[i][j] != 0) {
                fishes.insert({i, j, board[i][j]});
            }
        }
    }

    sol();
    printf("%d\n", fish_time);

    return 0;
}
