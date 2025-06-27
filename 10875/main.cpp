#include <iostream>

using namespace std;

int L, N;
int ts[1000];
char dirs[1000];
int boxes[1001][5]; // x1, y1, x2, y2, dir

void construct_boxes() {
    int dir = 0;    // > ^ < v

    // for 0
    boxes[0][0] = 0;
    boxes[0][1] = 0;
    boxes[0][2] = ts[0] - 1;
    boxes[0][3] = 0;
    boxes[0][4] = 0;
    boxes[1][0] = ts[0];
    boxes[1][1] = 0;
    if (dirs[0] == 'L') dir = (dir + 1) % 4;
    else dir = (dir + 3) % 4;

    // for 1 ~ n - 1
    for (int i = 1; i < N; i++) {
        switch (dir) {
            case 0:
                boxes[i][2] = boxes[i][0] + ts[i] - 1;
                boxes[i][3] = boxes[i][1];
                boxes[i][4] = dir;

                boxes[i + 1][0] = boxes[i][2] + 1;
                boxes[i + 1][1] = boxes[i][3];
                break;
            case 1:
                boxes[i][2] = boxes[i][0];
                boxes[i][3] = boxes[i][1] + ts[i] - 1;
                boxes[i][4] = dir;

                boxes[i + 1][0] = boxes[i][2];
                boxes[i + 1][1] = boxes[i][3] + 1;
                break;
            case 2:
                boxes[i][2] = boxes[i][0] - ts[i] + 1;
                boxes[i][3] = boxes[i][1];
                boxes[i][4] = dir;

                boxes[i + 1][0] = boxes[i][2] - 1;
                boxes[i + 1][1] = boxes[i][3];
                break;
            case 3:
                boxes[i][2] = boxes[i][0];
                boxes[i][3] = boxes[i][1] - ts[i] + 1;
                boxes[i][4] = dir;

                boxes[i + 1][0] = boxes[i][2];
                boxes[i + 1][1] = boxes[i][3] - 1;
                break;
            default:
                cout << "f: " << dir << '\n';
                break;
        }

        if (dirs[i] == 'L') dir = (dir + 1) % 4;
        else dir = (dir - 1) % 4;
    }

    // for n
    switch (dir) {
        case 0:
            boxes[N][2] = 100000001;
            boxes[N][3] = boxes[N][1];
            break;
        case 1:
            boxes[N][2] = boxes[N][0];
            boxes[N][3] = 100000001;
            break;
        case 2:
            boxes[N][2] = -100000001;
            boxes[N][3] = boxes[N][1];
            break;
        case 3:
            boxes[N][2] = boxes[N][0];
            boxes[N][3] = -100000001;
            break;
    }
    boxes[N][4] = dir;
}

bool is_collision(const int i, const int j, int &dt) {
    bool flag = false;
    int *box_i = boxes[i];
    int *box_j = boxes[j];

    if (box_i[4] % 2 == 0 && box_j[4] % 2 == 0 && box_i[1] == box_j[1]) {
        int i_min = min(box_i[0], box_i[2]);
        int i_max = max(box_i[0], box_i[2]);
        int j_min = min(box_j[0], box_j[2]);
        int j_max = max(box_j[0], box_j[2]);

        if (i_max < j_min || j_max < i_min) {
            return false;
        } else {
            return true;
        }
    }

    if (box_i[4] % 2 == 1 && box_j[4] % 2 == 1 && box_i[0] == box_i[0]) {
        int i_min = min(box_i[1], box_i[3]);
        int i_max = max(box_i[1], box_i[3]);
        int j_min = min(box_j[1], box_j[3]);
        int j_max = max(box_j[1], box_j[3]);

        if (i_max < j_min || j_max < i_min) {
            return false;
        } else {
            return true;
        }
    }

    if (box_i[4] % 2 == 0) {    // i: hor, j: ver
        int i_x_min = min(box_i[0], box_i[2]);
        int i_x_max = max(box_i[0], box_i[2]);
        int j_y_min = min(box_j[1], box_j[3]);
        int j_y_max = max(box_j[1], box_j[3]);

        if (i_x_min <= box_j[0] && box_j[0] <= i_x_max
                && j_y_min <= box_i[1] && box_i[1] <= j_y_max) {
            printf("a: %d, %d\n", box_i[1], box_j[0]);
            dt = abs(box_i[0] - box_j[0]);
            return true;
        } else {
            return false;
        }
    } else {                    // i: ver, j: hor
        int i_y_min = min(box_i[1], box_i[3]);
        int i_y_max = max(box_i[1], box_i[3]);
        int j_x_min = min(box_j[0], box_j[2]);
        int j_x_max = max(box_j[0], box_j[2]);

        if (i_y_min <= box_j[1] && box_j[1] <= i_y_max
                && j_x_min <= box_i[0] && box_i[0] <= j_x_max) {
            printf("a: %d, %d\n", box_i[0], box_j[1]);
            dt = abs(box_i[1] - box_j[1]);
            return true;
        } else {
            return false;
        }
    }

    return false;
}

bool is_out(const int i, int &dt) {
    const int x_max = max(boxes[i][0], boxes[i][2]);
    const int y_max = max(boxes[i][1], boxes[i][3]);
    const int x_min = min(boxes[i][0], boxes[i][2]);
    const int y_min = min(boxes[i][1], boxes[i][3]);

    const int w = abs(boxes[i][2] - boxes[i][0]) + 1;
    const int h = abs(boxes[i][3] - boxes[i][1]) + 1;

    if (x_max > L) {
        dt = x_max - L;
        dt = w - dt;
        return true;
    }
    if (y_max > L) {
        dt = y_max - L;
        dt = h - dt;
        return true;
    }
    if (x_min < -L) {
        dt = -L - x_min;
        dt = w - dt;
        return true;
    }
    if (y_min < -L) {
        dt = -L - y_min;
        dt = h - dt;
        return true;
    }

    return false;
}

void solve() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            int dt;
            if (is_collision(i, j, dt)) {
                printf("collision: %d, %d (%d)\n", i, j, dt);
                return;
            }
        }

        int dt;
        if (is_out(i, dt)) {
            printf("out: %d (%d)\n", i, dt);
            return;
        }
    }
}

int main() {
    cin >> L >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d %c", &ts[i], &dirs[i]);
    }

    construct_boxes();

    for (int i = 0; i <= N; i++) {
        cout << boxes[i][0] << ' ';
        cout << boxes[i][1] << ' ';
        cout << boxes[i][2] << ' ';
        cout << boxes[i][3] << ' ';
        cout << boxes[i][4] << ' ';
        cout << '\n';
    }

    solve();
}
