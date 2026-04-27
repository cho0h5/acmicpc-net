#include <iostream>

using namespace std;

int n;

void partial1(const int i) {
    for (int j = n * 2 - 1; j >= 0; j--) {
        printf("%c", i == j ? '*' : ' ');
    }
}

void partial2(const int i) {
    if (i < n) {
        for (int j = n - 1; j >= 0; j--) {
            printf("%c", i == j ? '*' : ' ');
        }
    } else {
        for (int j = n; j < n * 2; j++) {
            printf("%c", i == j ? '*' : ' ');
        }
    }
}

void partial3(const int i) {
    if (i < n) {
        for (int j = 0; j < n; j++) {
            printf("%c", i == j ? '*' : ' ');
        }
    } else {
        for (int j = n * 2 - 1; j >= n; j--) {
            printf("%c", i == j ? '*' : ' ');
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n * 2; i++) {
        partial1(i);
        printf(" ");
        partial2(i);
        printf(" ");
        partial3(i);
        printf("\n");
    }
}
