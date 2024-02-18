#include <iostream>

using namespace std;

int table[100001];
int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >>k;
	for (int i = 0; i < n; i++) {
		cin >> table[i + 1];
		table[i + 1] += table[i];
	}

//	for (int i = 0; i <= n; i++) {
//		cout << table[i] << ' ';
//	}
//	cout << '\n';

	int m = -2147483648;
	for (int i = k; i <= n; i++) {
		int tmp = table[i] - table[i - k];
		if (tmp > m)
			m = tmp;
	}
	cout << m << '\n';
}
