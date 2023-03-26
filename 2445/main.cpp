#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j <= n - i - 1; j++) printf("*");
        for(int j = 0; j < 2 * i; j++) printf(" ");
        for(int j = 0; j <= n - i - 1; j++) printf("*");
        printf("\n");
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n - i - 1; j++) printf("*");
        for(int j = 0; j < 2 * i; j++) printf(" ");
        for(int j = 0; j <= n - i - 1; j++) printf("*");
        printf("\n");
    }
}