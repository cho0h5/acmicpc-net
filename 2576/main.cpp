#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int count = 0;
    int min = 1000;
    int c = 7;
    int n;

    for (int i = 0; i < c; i++) {
        cin >> n;
        if (n % 2 == 1) {
            sum += n;
            count++;
            if (min > n) min = n;
        }
    }

    if (count == 0) {
        cout << -1;
        cout << "\n";
    } else {
        cout << sum;
        cout << "\n";
        cout << min;
        cout << "\n";
    }
}
