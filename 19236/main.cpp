#include <iostream>
#include <cstring>

using namespace std;

int map_name[4][4];
int map_fishes[17][2];
int map_dir[4][4];

int dup_name[4][4];
int dup_fishes[17][2];
int dup_dir[4][4];

int arr[15];

const int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
const int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

int sol() {
    memcpy(dup_name, map_name, sizeof(dup_name));
    memcpy(dup_fishes, map_fishes, sizeof(dup_fishes));
    memcpy(dup_dir, map_dir, sizeof(dup_dir));

    // Put shark
    int x = 0;
    int y = 0;
    int score = 0;
    int step = 0;

    while (1) {
        if (x < 0 || x >= 4 || y < 0 || y >= 4) {
            break;
        }

        if (dup_name[x][y] == 0) {
            break;
        }

        const int target = dup_name[x][y];
        dup_name[x][y] = 0;
        score += target;
        dup_fishes[target][0] = -1;
        dup_fishes[target][1] = -1;

        int nx = x + dx[dup_dir[x][y]] * arr[step];
        int ny = y + dy[dup_dir[x][y]] * arr[step];
        dup_dir[x][y] = 0;
        x = nx;
        y = ny;
        step += 1;
    }

    return score;
}

void backtracking(int step) {
    if (step == 15) {
        const int score = sol();
        if (score != -1)
            printf("%d\n", score);
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
}
