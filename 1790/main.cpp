#include <iostream>

using namespace std;

int n, k;

int pow(int base, int exp) {
    int result = 1;
    for (; exp; exp--) {
        result *= base;
    }
    return result;
}

int main() {
    // cin >> n >> k;


    int i = 1;
    int base = 0;
    while (base < 100000000) {
        base += i * 9 * pow(10, i - 1);
        i += 1;
        cout << base << '\n';
    }
}
