#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a[5];
    cin >> a[0];
    cin >> a[1];
    cin >> a[2];
    cin >> a[3];
    cin >> a[4];

    sort(a, a + 5);

    cout << (a[0] + a[1] + a[2] + a[3] + a[4]) / 5 << "\n";
    cout << a[2] << "\n";
}
