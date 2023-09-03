#include <iostream>
#include <algorithm>

using namespace std;

int ns[7];
int p[7];
int n, t;
int cnt;

void perm(int s) {
    if (s == t) {
        for (int i = 0; i < t; i++) {
            cout << ns[p[i]] << ' ';
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
        for (int i = 0; i < n; i++) {
            p[s] = i;
            perm(s + 1);
        }
    }
}

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> ns[i];
    sort(ns, ns + n);

    perm(0);
}
