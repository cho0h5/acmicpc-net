#include <stdio.h>

int fib(int n);

int main() {
    int x;
    scanf("%d", &x);
    printf("%d\n", fib(x));
    return 0;
}

int fib(int n) {
    int a = 0;
    int b = 1;

    for (int i = 0; i < n; i++) {
        a += b;
        int tmp = a;
        a = b % 1000000007;
        b = tmp % 1000000007;
    }

    return a;
}
