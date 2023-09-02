#include <iostream>

using namespace std;

int board[2787][2787];
int n;

void printb() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

typedef struct cc_ {
    int is_same;
    int a;
    int b;
    int c;
} cc;

void printc(cc c) {
    cout << c.is_same << '\n';
    cout << c.a << '\n';
    cout << c.b << '\n';
    cout << c.c << '\n';
}

cc recursion(int x, int y, int s) {
    cc ret; ret.is_same = 0; ret.a = 0; ret.b = 0; ret.c = 0;

    if (s == 1) {
        ret.is_same = 1;
        if (board[x][y] == -1) ret.a++;
        if (board[x][y] == 0) ret.b++;
        if (board[x][y] == 1) ret.c++;
        return ret;
    }

    s /= 3;

    int temp = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[x][y] != board[x + i * s][y + j * s]) temp = 0;

            cc result = recursion(x + i * s, y + j * s, s);
            ret.is_same += result.is_same;
            ret.a += result.a;
            ret.b += result.b;
            ret.c += result.c;
        }
    }
    if (ret.is_same == 9 && temp) {
        ret.is_same = 1;
        ret.a /= 9;
        ret.b /= 9;
        ret.c /= 9;
        return ret;
    }

    ret.is_same = 0;
    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cc result = recursion(0, 0, n);
    cout << result.a << '\n';
    cout << result.b << '\n';
    cout << result.c << '\n';
}
