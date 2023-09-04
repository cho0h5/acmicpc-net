#include <iostream>
#include <algorithm>

using namespace std;

int ns[12];
int p[12];
int n;

void sol() {
    do {
        for (int i = 0; i < n; i++) {
            if (p[i] == 0)
                cout << ns[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(p, p + n));
}

int main() {
    while (1) {
        cin >> n;
        if (n == 0) return 0;

        for (int i = 0; i < n; i++) {
            cin >> ns[i];
            p[i] = i >= 6;
        }
        sort(ns, ns + n);
        sol();
        cout << '\n';
    }
}
