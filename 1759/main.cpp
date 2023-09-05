#include <iostream>

using namespace std;

char cs[15];
int l, c;
int p[15];
char r[15];

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> cs[i];
        p[i] = i >= l;
    }
    sort(cs, cs + c);

    do {
        int j = 0;
        int mo_cnt = 0;
        int ja_cnt = 0;
        for (int i = 0; i < c; i++) {
            if (p[i] == 0) {
                r[j++] = cs[i];
                if (cs[i] == 'a' || cs[i] == 'e' || cs[i] == 'i' || cs[i] == 'o' || cs[i] == 'u') mo_cnt++;
                else ja_cnt++;
            }
        }
        int flag = 1;
        for (int i = 1; i < l; i++) {
            if (r[i - 1] > r[i]) flag = 0;
        }
        if (mo_cnt >= 1 && ja_cnt >= 2 && flag) {
            for (int i = 0; i < l; i++) cout << r[i];
            cout << '\n';
        }
    } while (next_permutation(p, p + c));
}
