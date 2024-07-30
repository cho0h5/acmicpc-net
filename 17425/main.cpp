#include <iostream>

using namespace std;

long long n;
long long table[1000001];
long long table2[1000001];

void sol() {
	for (int i = 1; i <= 1000000; i++) {
		for (int j = i; j <= 1000000; j += i) {
			table[j] += i;
		}
	}

	for (int i = 1; i <= 1000000; i++) {
		table2[i] = table2[i - 1] + table[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	sol();

	cin >> n;
	long long x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cout << table2[x] << '\n';
	}
}
