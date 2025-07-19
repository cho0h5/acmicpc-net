#include <iostream>
#include <queue>

using namespace std;

int n, k;
int color[12][12];
deque<int> board[12][12];
int horse[10][4];   // x, y, h, dir

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

bool move_horse(const int i, const bool blue_flag) {
    const int cx = horse[i][0];
    const int cy = horse[i][1];
    const int ch = horse[i][2];
    const int cd = horse[i][3];

    if (ch > 0) {
        return false;
    }

    const int nx = cx + dx[cd];
    const int ny = cy + dy[cd];
    int next_color = 2;
    if (!(nx < 0 || nx >= n || ny < 0 || ny >= n)) {
        next_color = color[nx][ny];
    }

    switch (next_color) {
        case 0:
            // 전부 이동하여 그대로 쌓기
            while (board[cx][cy].size()) {
                const int horse_i = board[cx][cy].front();
                board[cx][cy].pop_front();
                horse[horse_i][0] = nx;
                horse[horse_i][1] = ny;
                horse[horse_i][2] = board[nx][ny].size();
                board[nx][ny].push_back(horse_i);
            }
            if (board[nx][ny].size() >= 4) {
                return true;
            }
            break;

        case 1:
            // 전부 이동하여 거꾸로 쌓기
            while (board[cx][cy].size()) {
                const int horse_i = board[cx][cy].back();
                board[cx][cy].pop_back();
                horse[horse_i][0] = nx;
                horse[horse_i][1] = ny;
                horse[horse_i][2] = board[nx][ny].size();
                board[nx][ny].push_back(horse_i);
            }
            if (board[nx][ny].size() >= 4) {
                return true;
            }
            break;

        case 2:
            if (blue_flag) {
                return false;
            } else {
                if (cd == 0) horse[i][3] = 1;
                else if (cd == 1) horse[i][3] = 0;
                else if (cd == 2) horse[i][3] = 3;
                else if (cd == 3) horse[i][3] = 2;
                return move_horse(i, true);
            }
            break;
    }
    return false;
}

bool step() {
    for (int i = 0; i < k; i++) {
        if (move_horse(i, false)) {
            return true;
        }
    }
    return false;
}

void print_board() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%ld ", board[i][j].size());
        }
        printf("\n");
    }
    for (int i = 0; i < k; i++) {
        printf("%d: (%d, %d, %d), %d\n", i, horse[i][0], horse[i][1], horse[i][2], horse[i][3]);
    }
    printf("\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> color[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        horse[i][0] = x - 1;
        horse[i][1] = y - 1;
        horse[i][2] = 0;
        horse[i][3] = d - 1;

        board[horse[i][0]][horse[i][1]].push_back(i);
    }

    // print_board();
    for (int i = 0; i < 1000; i++) {
        if (step()) {
            printf("%d\n", i + 1);
            return 0;
        }
        // print_board();
    }
    printf("-1\n");
    return 0;
}
