#include <iostream>
#include <algorithm>

using namespace std;

int n;
int ns[8];
int ms[8];
int temp[8];
int p[8];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ns[i] >> ms[i];
        p[i] = i;
    }

    int cnt = 0;
    do {
        int flag = 1;
        for (int i = 0; i < n; i++) temp[i] = ns[i];
        for (int i = 0; i < n; i++) {
            if (temp[i] > 0 && i == p[i]) {
                flag = 0;
                break;
            }
            if (temp[i] <= 0 || temp[p[i]] <= 0) continue;
            temp[i] -= ms[p[i]];
            temp[p[i]] -= ms[i];
        }
        if (flag) {
            int acnt = 0;
            for (int i = 0; i < n; i++)
                if (temp[i] <= 0) acnt++;
            if (acnt > cnt) cnt = acnt;
        }
    } while (next_permutation(p, p + n));
    cout << cnt << '\n';
}
