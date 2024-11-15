#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 4 == 0) {
		cout << "CY\n";
	} else {
		cout << "SK\n";
	}
}

// 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
// S
// S  S
// S  S  S
// S  S  S  C
// S  S  C  C
// S  C  C  C
// S  C  C  C  S
// S  S  C  C  C  S
// S  S  C  C  S  S
// S  S  C  S  S  S
// S  S  S  C  C  C  S
// S  S  S  C  C  S  S
// S  S  S  C  S  S  S
