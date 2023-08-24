#include <iostream>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n;
    m = n;
    if (m == 0)
        return 0;
    n = 1;
    while (n < m) {
        for (int i = 0; i < m - n; i++) {
            cout << ' ';
        }
        for (int i = 0; i < n * 2 - 1; i++) {
            cout << '*';
        }
        cout << '\n';
        n++;
    }
    n = m;
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
