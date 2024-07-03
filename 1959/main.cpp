#include <iostream>

using namespace std;

long long sol_count(long long m, long long n) {
    if (m <= n) {
        return (m - 1) * 2;
    } else {
        return (n * 2) - 1;
    }
}

pair<long long, long long> sol_coor(long long m, long long n) {
    if (m - 1 <= n) {
        long long x = (m + 2) / 2;
        long long y;
        if (m % 2 == 0) {
            y = x - 1;
        } else {
            y = x + n - m;
        }
        return make_pair(x, y);
    } else {
        long long x;
        long long y = (n + 1) / 2;
        if (n % 2 == 0) {
            x = y + 1;
        } else {
            x = y + m - n;
        }
        return make_pair(x, y);
    }
}

int main() {
    long long m, n;
    cin >> m >> n;

    long long res_count = sol_count(m, n);
    pair<long long, long long> res_coor = sol_coor(m, n);

    cout << res_count << '\n';
    cout << res_coor.first << ' ' << res_coor.second << '\n';
}
