#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long A, B, C;
    long long acc = 1;
    cin >> A >> B >> C;

    // 1
    A = A % C;
    // cout << "[B & 0x01] " << (B & 0x01) << '\n';
    if(B & 0x01) acc = acc * A % C;
    // cout << "[A] " << A << '\n';
    // cout << "[acc] " << acc << '\n';
    B = B >> 1;

    // 2, 4, 8,...
    for(; B > 0; B = B >> 1) {
	A = A * A % C;
	// cout << "[B & 0x01] " << (B & 0x01) << '\n';
	if(B & 0x01) acc = acc * A % C;
	// cout << "[A] " << A << '\n';
	// cout << "[acc] " << acc << '\n';
    }
    cout << acc;
}
