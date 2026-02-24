#include <iostream>

using namespace std;

inline void print(const int num) {
    for (int i = 0; i < 10; i++) {
        printf("%s", (num >> i) & 1 ? "Aa" : "BB");
    }
    printf("\n");
}

void sol(const int k) {
    for (int i = 0; i < k; i++) {
        print(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;

    sol(k);

    return 0;
}
