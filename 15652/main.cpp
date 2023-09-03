#include <iostream>
#include <algorithm>

using namespace std;

int p[20];
int n, t;
int cnt;

void perm(int s) {
    if (s == t) {
        for (int i = 0; i < t; i++) {
            cout << p[i] + 1 << ' ';
        }
        cout << '\n';
        return ;
    }

    if (s == 0) {
        for (int i = 0; i < n; i++) {
            p[s] = i;
            perm(s + 1);
        }
    } else {
        for (int i = p[s - 1]; i < n; i++) {
            p[s] = i;
            perm(s + 1);
        }
    }
}

int main() {
    cin >> n >> t;

    perm(0);
}
