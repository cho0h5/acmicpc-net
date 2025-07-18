#include <iostream>
#include <cstring>

using namespace std;

struct State {
    int name[4][4];
    int dir[4][4];

    int shark[2];
    int fishes[16][2];

    int score;
};

int maximum = -1;

const int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
const int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

void move_fishes(State &state) {
    for (int i = 0; i < 16; i++) {
        if (state.fishes[i][0] == -1) {
            continue;
        }

        const int cx = state.fishes[i][0];
        const int cy = state.fishes[i][1];
        int nx = -1;
        int ny = -1;

        // Redirect
        for (int j = 0; j < 8; j++) {
            const int cd = state.dir[cx][cy];
            nx = cx + dx[cd];
            ny = cy + dy[cd];

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || (nx == state.shark[0] && ny == state.shark[1])) {
                state.dir[cx][cy] += 1;
                if (state.dir[cx][cy] >= 9) {
                    state.dir[cx][cy] = 1;
                }
                continue;
            }

            break;
        }

        if (state.name[nx][ny] != 0) {  // If there is fish, switch
            const int other_fish_i = state.name[nx][ny] - 1;

            swap(state.name[nx][ny], state.name[cx][cy]);
            swap(state.dir[nx][ny], state.dir[cx][cy]);

            state.fishes[i][0] = nx;
            state.fishes[i][1] = ny;
            state.fishes[other_fish_i][0] = cx;
            state.fishes[other_fish_i][1] = cy;
        } else {    // else, just move
            swap(state.name[nx][ny], state.name[cx][cy]);
            swap(state.dir[nx][ny], state.dir[cx][cy]);
            
            state.fishes[i][0] = nx;
            state.fishes[i][1] = ny;
        }
    }
}

void print_state(const State &state, const int step) {
    printf("step: %d\n", step);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", state.name[i][j]);
        }
        printf("\n");
    }
    printf("shark: (%d, %d)\n", state.shark[0], state.shark[1]);
    printf("score: %d\n", state.score);
    printf("\n");
}

void backtracking(State state, const int n, const int step) {
    // Simul
    const int scx = state.shark[0];
    const int scy = state.shark[1];
    const int scd = state.dir[scx][scy];
    const int snx = scx + dx[scd] * n;
    const int sny = scy + dy[scd] * n;

    // Check if it is possible to move
    if (snx < 0 || snx >= 4 || sny < 0 || sny >= 4) {
        if (state.score > maximum) {
            maximum = state.score;
            // printf("maximum: %d\n", maximum);
        }
        return;
    }

    // Check if there is a fish
    if (state.name[snx][sny] == 0) {
        if (state.score > maximum) {
            maximum = state.score;
            // printf("maximum: %d\n", maximum);
        }
        return;
    }

    // Shark eat a fish
    const int fish_i = state.name[snx][sny] - 1;
    state.score += fish_i + 1;
    state.name[snx][sny] = 0;
    // Remove fish
    state.fishes[fish_i][0] = -1;
    state.fishes[fish_i][1] = -1;
    // Move Shark
    state.shark[0] = snx;
    state.shark[1] = sny;

    // printf("-------- after move shark\n");
    // print_state(state, step);

    // Move fishes
    move_fishes(state);
    // printf("-------- after move fishes\n");
    // print_state(state, step);

    // Keep going backtracking
    backtracking(state, 1, step + 1);
    backtracking(state, 2, step + 1);
    backtracking(state, 3, step + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    State state;
    state.shark[0] = 0;
    state.shark[1] = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> state.name[i][j];
            cin >> state.dir[i][j];
            state.fishes[state.name[i][j] - 1][0] = i;
            state.fishes[state.name[i][j] - 1][1] = j;
        }
    }
    const int fish_i = state.name[0][0] - 1;
    state.name[0][0] = 0;
    state.score = fish_i + 1;
    state.fishes[fish_i][0] = -1;
    state.fishes[fish_i][1] = -1;

    // print_state(state, -1);

    // Move fishes
    move_fishes(state);

    backtracking(state, 1, 0);
    backtracking(state, 2, 0);
    backtracking(state, 3, 0);

    printf("%d\n", maximum);
}
