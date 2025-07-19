#include <iostream>

using namespace std;

int convert(const int x) {
    switch (x % 4) {
        case 0:
            return x;
            break;

        case 1:
            return 1;
            break;

        case 2:
            return x + 1;
            break;

        case 3:
            return 0;
            break;

    }
    return -1;
}

int sol(const int s, const int f) {
    return convert(s - 1) ^ convert(f);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int s, f;
        cin >> s >> f;
        const int result = sol(s, f);
        printf("%d\n", result);
    }

//    int acc = 0;
//    for (int i = 0; i <= 64; i++) {
//        acc ^= i;
//        printf("%2d: ", i);
//        printf("%d\n", acc);
//    }
}
