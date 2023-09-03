#include <iostream>
#include <algorithm>

using namespace std;

int ns[20];
int p[20];
int n, ss;
int cnt;

void perm(int s, int t) {
    if (s == t) {
        int sum = 0;
        for (int i = 0; i < t; i++) {
            sum += ns[p[i]];
        }
        if (sum == ss) cnt++;
        return ;
    }

    if (s == 0) {
        for (int i = 0; i < n; i++) {
            p[s] = i;
            perm(s + 1, t);
        }
    } else {
        for (int i = p[s - 1] + 1; i < n; i++) {
            p[s] = i;
            perm(s + 1, t);
        }
    }
}

int main() {
    cin >> n >> ss;
    for (int i = 0; i < n; i++) {
        cin >> ns[i];
    }

    for (int i = 1; i <= n; i++)
        perm(0, i);

    cout << cnt << '\n';
}
