#include <iostream>

using namespace std;

int table[15];
int dp;

int main() {
	table[0] = 3;
	dp = 2;
	int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << "0\n";
		return 0;
	}
	n = n / 2 - 1;
	for (int i = 1; i <= n; i++) {
		// cout << "debug: " << table[i - 1] << ' ' << dp << '\n';
		table[i] = table[i - 1] * 3 + dp;
		dp += table[i - 1] * 2;
	}

//	for (int i = 0; i <= n; i++) {
//		cout << table[i] << ' ';
//	}
//	cout << '\n';

	cout << table[n] << '\n';
}
