#include <iostream>

using namespace std;

unsigned long n;
unsigned long arr[1000000];
unsigned long table[20];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        for (int j = 0; j < 20; j++) {
            table[j] += (arr[i] & (0b1 << j)) > 0;
        }
    }

//    for (int i = 0; i < 20; i++) {
//        cout << table[i] << ' ';
//    }
//    cout << '\n';

    unsigned long acc = 0;
    for (int i = 0; i < n; i++) {

        unsigned long g = 1;
        for (int j = 0; j < 20; j++) {
            const int digit = (arr[i] & (0b1 << j)) > 0;

            if (digit) {
                acc += g * (n - table[j]);
                // cout << n - table[j] << ' ';
            } else {
                acc += g * table[j];
                // cout << table[j] << ' ';
            }

            g *= 2;
        }
        // cout << ": " << acc << ' ';
        // cout << '\n';
    }
    // cout << acc << '\n';
    cout << (acc >> 1) << '\n';
}
