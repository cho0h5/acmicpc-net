#include <iostream>

using namespace std;

long long n, k;

long long pow(long long base, long long exp) {
    long long result = 1;
    for (; exp; exp--) {
        result *= base;
    }
    return result;
}

void check_bound(long long num) {
    if (num > n) {
        cout << "-1\n";
        exit(0);
    }
}

long long get_digit(long long num, long long i) {
    return (long long)(num / pow(10, i)) % 10;
}

int main() {
    cin >> n >> k;

    long long i = 1;
    long long base = 0;
    long long acc = 0;
    while (base < 100000000000) {
        base = i * 9 * pow(10, i - 1);

        if (k <= base) {
            long long quotient = (k - 1) / i;
            long long remainder = (k - 1) % i;

            long long num = acc + quotient + 1;
            check_bound(num);
            // cout << num << '\n';
            // cout << remainder << '\n';
            cout << get_digit(num, i - remainder - 1) << '\n';

            return 0;
        }

        acc += 9 * pow(10, i - 1);
        k -= base;
        i += 1;
    }
}
