#include <iostream>
#include <cmath>

using namespace std;

int recursion(int n, int x, int y) {
    // cout << "[debug] " << n << ' ' << x << ' ' << y << '\n';
    if(n == 1) {
	return (x << 1) | y;
    }


    int base = pow(2, n * 2 - 2) * recursion(1, x >> (n-1), y >> (n-1));
    // cout << "[base] " << base << '\n';
    return base
	+ recursion(n-1, x & (~(1 << (n - 1))), y & (~(1 << (n - 1))));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    cout << recursion(a, b, c);
}
