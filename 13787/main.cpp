#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

long long h, w, l;
char board[100][100];
long long vst[100][100][4];

struct Robot {
    int x;
    int y;
    int dir;

    bool can_forward() {
        const int nx = x + dx[dir];
        const int ny = y + dy[dir];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w) return false;
        return board[nx][ny] == '.';
    }

    void turn_right() {
        dir = (dir + 1) % 4;
    }

    void forward() {
        while (!can_forward()) {
            turn_right();
        }

        x += dx[dir];
        y += dy[dir];
    }

    void print() {
        printf("Robot: (%d, %d), %d\n", x, y, dir);
    }

    void print_answer() {
        char c;
        switch (dir) {
            case 0:
                c = 'E';
                break;
            case 1:
                c = 'S';
                break;
            case 2:
                c = 'W';
                break;
            case 3:
                c = 'N';
                break;
        }
        printf("%d %d %c\n", x + 1, y + 1, c);
    }
};

vector<Robot> history;
Robot robot;

void print_debug() {
    robot.print();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void init() {
    fill((bool*)vst, (bool*)vst + sizeof(vst) / sizeof(bool), false);

    history.clear();
}

void sol() {
    // printf("----------------\n");

    // print_debug();

    while (true) {
        robot.forward();

        if (vst[robot.x][robot.y][robot.dir]) break;

        history.push_back(robot);
        vst[robot.x][robot.y][robot.dir] = history.size();

        // robot.print();
    }

    // printf("size: %zu\n", history.size());
    long long last = vst[robot.x][robot.y][robot.dir];
    // printf("last: %lld\n", last);
    // robot.print();

    long long last_index;
    if (l <= history.size() - 2) {
        last_index = l;
    } else {
        last_index = (l - last + 1) % (history.size() - last + 1) + last - 1;
    }

    // printf("last_index: %lld\n", last_index);

    // history[last_index].print();
    history[last_index].print_answer();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        init();

        cin >> h >> w >> l;

        if (h == 0) break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char cell;
                cin >> cell;

                if (cell == '#') {
                    board[i][j] = '#';
                } else {
                    board[i][j] = '.';
                }

                if (cell == 'E') {
                    robot.x = i;
                    robot.y = j;
                    robot.dir = 0;
                    history.push_back(robot);
                    vst[robot.x][robot.y][robot.dir] = history.size();
                } else if (cell == 'S') {
                    robot.x = i;
                    robot.y = j;
                    robot.dir = 1;
                    history.push_back(robot);
                    vst[robot.x][robot.y][robot.dir] = history.size();
                } else if (cell == 'W') {
                    robot.x = i;
                    robot.y = j;
                    robot.dir = 2;
                    history.push_back(robot);
                    vst[robot.x][robot.y][robot.dir] = history.size();
                } else if (cell == 'N') {
                    robot.x = i;
                    robot.y = j;
                    robot.dir = 3;
                    history.push_back(robot);
                    vst[robot.x][robot.y][robot.dir] = history.size();
                }
            }
        }

        sol();
    }

    return 0;
}
