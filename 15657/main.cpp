#include <iostream>
#include <algorithm>

using namespace std;

int ns[8];
int p[8];
int n, t;
int cnt;
int isused[8];

void perm(int s) {
    if (s == t) {
        for (int i = 0; i < t; i++) {
            cout << ns[p[i]] << ' ';
            // cout << p[i] << ' ';
        }
        cout << '\n';
        return ;
    }

    if (s == 0) {
        int prevv = -1;
        for (int i = 0; i < n; i++) {
            p[s] = i;
            if (isused[i] == 1) continue;
            if (prevv == ns[i]) continue;
            isused[i] = 1;
            perm(s + 1);
            isused[i] = 0;
            prevv = ns[i];
        }
    } else {
        int prevv = -1;
        for (int i = 0; i < n; i++) {
            p[s] = i;
            if (isused[i] == 1) continue;
            if (prevv == ns[i]) continue;
            isused[i] = 1;
            perm(s + 1);
            isused[i] = 0;
            prevv = ns[i];
        }
    }
}

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> ns[i];
    sort(ns, ns + n);

    perm(0);
}
