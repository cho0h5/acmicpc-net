#include <iostream>

using namespace std;

char a[1001];
char b[1001];
int aa[26];
int bb[26];

int abs(int x) {
    if (x > 0) {
        return x;
    }
    return -x;
}

void count(char *c, int *cc) {
    int i = 0;
    while (c[i] != 0) {
        cc[c[i] - 'a']++;
        i++;
    }
}

int main() {
    cin >> a >> b;
    count(a, aa);
    count(b, bb);

    int count = 0;
    for(int i = 0; i < 26; i++) {
        count += abs(aa[i] - bb[i]);
    }
    cout << count << '\n';

}
