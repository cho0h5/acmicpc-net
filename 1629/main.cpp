#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A, B, C;
    int acc;
    cin >> A >> B >> C;
    while(B--) {
	acc = acc * A % C;
    }
    cout << acc;
}
