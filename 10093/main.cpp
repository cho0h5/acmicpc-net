#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    if (a == b) {
        cout << '0';
    } else if (a < b) {
        cout << b - a - 1 << '\n';
        for(long long i = a + 1; i < b; i++) {
            cout << i << ' ';
        }
    } else {
        cout << a - b - 1 << '\n';
        for(long long i = b + 1; i < a; i++) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}
