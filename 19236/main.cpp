#include <iostream>
#include <cstring>

using namespace std;

int map_name[4][4];
int map_fishes[17][2];
int map_dir[4][4];

int dup_name[4][4];
int dup_fishes[17][2];
int dup_dir[4][4];

int arr[16];

int maximum = -1;

const int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
const int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

void swap_fish(const int a, const int b) {
    const int ax = dup_fishes[a][0];
    const int ay = dup_fishes[a][1];
    const int bx = dup_fishes[b][0];
    const int by = dup_fishes[b][1];

    dup_fishes[a][0] = bx;
    dup_fishes[a][1] = by;
    dup_fishes[b][0] = ax;
    dup_fishes[b][1] = ay;

    // dup_name[ax][ay] = b + 1;
    // dup_name[bx][by] = a + 1;

    // printf("%d, %d\n", ax, ay);
    const int tmp = dup_name[ax][ay];
    dup_name[ax][ay] = dup_name[bx][by];
    dup_name[bx][by] = tmp;

    const int temp = dup_dir[ax][ay];
    dup_dir[ax][ay] = dup_dir[bx][by];
    dup_dir[bx][by] = temp;
}

void move_fishes(const int sx, const int sy) {
    for (int i = 0; i < 16; i++) {
        if (dup_fishes[i][0] == -1) {
            continue;
        }

        const int x = dup_fishes[i][0];
        const int y = dup_fishes[i][1];
        int nx = -1;
        int ny = -1;
        for (int i = 0; i < 8; i++) {
            const int dir = dup_dir[x][y];
            nx = x + dx[dir];
            ny = y + dy[dir];

            if (nx == sx && ny == sy) {
                dup_dir[x][y] += 1;
                if (dup_dir[x][y] == 9) {
                    dup_dir[x][y] = 1;
                }
                continue;
            }

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
                dup_dir[x][y] += 1;
                if (dup_dir[x][y] == 9) {
                    dup_dir[x][y] = 1;
                }
                continue;
            }

            break;
        }

        if (dup_name[nx][ny] != 0) {
            // printf("dup_name: %d\n", dup_name[nx][ny]);
            swap_fish(dup_name[nx][ny] - 1, i);
        } else {
            dup_fishes[i][0] = nx;
            dup_fishes[i][1] = ny;

            dup_name[nx][ny] = dup_name[x][y];
            dup_name[x][y] = 0;

            dup_dir[nx][ny] = dup_dir[x][y];
            dup_dir[x][y] = 0;
        }
    }
}

int sol() {
    // printf("---- new game ----\n");
    memcpy(dup_name, map_name, sizeof(dup_name));
    memcpy(dup_fishes, map_fishes, sizeof(dup_fishes));
    memcpy(dup_dir, map_dir, sizeof(dup_dir));

    // Put shark
    int x = 0;
    int y = 0;
    int score = 0;
    int step = 0;

    while (1) {
        if (step >= 15) {
            break;
        }

        if (x < 0 || x >= 4 || y < 0 || y >= 4) {
            break;
        }

        if (dup_name[x][y] == 0) {
            break;
        }

        const int target = dup_name[x][y];
        // printf("ate: %d\n", target);
        dup_name[x][y] = 0;
        score += target;
        dup_fishes[target - 1][0] = -1;
        dup_fishes[target - 1][1] = -1;

        int nx = x + dx[dup_dir[x][y]] * arr[step];
        int ny = y + dy[dup_dir[x][y]] * arr[step];
        dup_dir[x][y] = 0;
        x = nx;
        y = ny;
        step += 1;

        move_fishes(x, y);
    }

    return score;
}

void backtracking(int step) {
    if (step == 15) {
        const int score = sol();
        if (score > maximum) {
            // printf("new: %d\n", score);
            maximum = score;
        }
        return;
    }

    for (int i = 1; i <= 3; i++) {
        arr[step] = i;
        backtracking(step + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> map_name[i][j];
            cin >> map_dir[i][j];
            map_fishes[map_name[i][j]][0] = i;
            map_fishes[map_name[i][j]][1] = j;
        }
    }

    for (int i = 1; i <= 3; i++) {
        arr[0] = i;
        backtracking(1);
    }

    printf("%d\n", maximum);
}
