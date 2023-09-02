#include <iostream>

using namespace std;

char board[64][65];
int n;

bool check(int x, int y, int s) {
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            if (board[x][y] != board[x + i][y + j])
                return false;
    return true;
}

void recursion(int x, int y, int s) {
    if (check(x, y, s)) {
        cout << board[x][y];
        return;
    }
    cout << '(';
    s /= 2;
    recursion(x, y, s);
    recursion(x, y + s, s);
    recursion(x + s, y, s);
    recursion(x + s, y + s, s);
    cout << ')';
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    recursion(0, 0, n);
    cout << '\n';
}
