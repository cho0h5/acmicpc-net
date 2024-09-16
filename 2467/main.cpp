#include <iostream>

using namespace std;

int n;
int ns[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ns[i];
    }

    int i = 0;
    int j = n - 1;

    int minimum = 2147483647;
    int left = ns[i];
    int right = ns[j];

    while (i < j) {
        int temp = abs(ns[i] + ns[j]);
        if (temp < minimum) {
            minimum = temp;
            left = ns[i];
            right = ns[j];
        }

        if (abs(ns[i] + ns[j - 1]) < abs(ns[i + 1] + ns[j])) {
            j -= 1;
        } else {
            i += 1;
        }
    }

    cout << left << ' ' << right << '\n';
}
