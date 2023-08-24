#include <iostream>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n;
    m = n;
    while (n) {
        for (int i = 0; i < m - n; i++) {
            cout << ' ';
        }
        for (int i = 0; i < n * 2 - 1; i++) {
            cout << '*';
        }
        cout << '\n';
        n--;
    }
}
