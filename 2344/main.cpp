#include <iostream>

using namespace std;

int n, m;
int mirror[1000][1000];

int convert(const int x, const int y) {
    if (x < 0) {
        return n + m + n + (m - y);
    } else if (x >= n) {
        return n + y + 1;
    } else if (y < 0) {
        return x + 1;
    } else {
        return n + m + (n - x);
    }
}

int sol(int x, int y, int dir) {
    while (1) {
        if (mirror[x][y]) {   // on mirror
            switch (dir) {
                case 0:
                    dir = 1;
                    break;

                case 1:
                    dir = 0;
                    break;

                case 2:
                    dir = 3;
                    break;

                case 3:
                    dir = 2;
                    break;

            }
        }

        switch (dir) {
            case 0:
                y += 1;
                break;

            case 1:
                x -= 1;
                break;

            case 2:
                y -= 1;
                break;

            case 3:
                x += 1;
                break;
        }

        if (x < 0 || x >= n || y < 0 || y >= m) {
            return convert(x, y);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mirror[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        const int result = sol(i, 0, 0);        // 0: right
        cout << result << ' ';
    }
    for (int j = 0; j < m; j++) {
        const int result = sol(n - 1, j, 1);    // 1: up
        cout << result << ' ';
    }
    for (int i = n - 1; i >= 0; i--) {
        const int result = sol(i, m - 1, 2);    // 2: left
        cout << result << ' ';
    }
    for (int j = m - 1; j >= 0; j--) {
        const int result = sol(0, j, 3);
        cout << result << ' ';
    }
    cout << '\n';

    return 0;
}
