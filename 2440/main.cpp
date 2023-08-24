#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n) {
        for (int i = 0; i < n; i++) {
            cout << '*';
        }
        cout << '\n';
        n--;
    }
}
