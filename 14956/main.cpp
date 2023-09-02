#include <iostream>

using namespace std;

int n, m;

pair<int, int> sol(int s, int x) {
    // cout << s << ' ' << x << '\n';
    if (s <= 2) {
        switch (x) {
            case 0:
                return make_pair(1, 1);
            case 1:
                return make_pair(1, 2);
            case 2:
                return make_pair(2, 2);
            case 3:
                return make_pair(2, 1);
        }
    }
    int b = s / 2;
    b *= b;

    if (0 * b <= x && x < 1 * b) {
        pair<int, int> r = sol(s / 2, x - 0 * b);
        int temp = r.first;
        r.first = r.second;
        r.second = temp;
        // cout << "-> " << r.first << ' ' << r.second << '\n';
        return r;
    } else if (1 * b <= x && x < 2 * b) {
        pair<int, int> r = sol(s / 2, x - 1 * b);
        r.second += s / 2;
        // cout << "-> " << r.first << ' ' << r.second << '\n';
        return r;
    } else if (2 * b <= x && x < 3 * b) {
        pair<int, int> r = sol(s / 2, x - 2 * b);
        r.first += s / 2;
        r.second += s / 2;
        // cout << "-> " << r.first << ' ' << r.second << '\n';
        return r;
    } else if (3 * b <= x && x < 4 * b) {
        pair<int, int> r = sol(s / 2, x - 3 * b);
        int temp = r.first;
        r.first = r.second;
        r.second = temp;
        r.first = s / 2 - r.first + 1;
        r.second = s / 2 - r.second + 1;
        r.first += s / 2;
        // cout << "-> " << r.first << ' ' << r.second << '\n';
        return r;
    }
    return make_pair(0, 0);
}

int main() {
    cin >> n >> m;
    pair<int, int> r = sol(n, m - 1);
    cout << r.first << ' ' << r.second << '\n';
}
