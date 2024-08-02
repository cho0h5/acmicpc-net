#include <iostream>
#include <vector>

using namespace std;

int t;
int n, m, k;

int sol(const vector<int> &houses) {
	int count = 0;

	int p = 0;
	int q = 0;
	int state = 0;

	for (; q < m; q++) {
		state += houses[q];
	}
	if (state < k) {
		count += 1;
	}
	// cout << "state: " << state << '\n';
	if (n == m) return count;

	for (int i = 1; i < n; i++) {
		state -= houses[p++];
		state += houses[q++];
		p %= n;
		q %= n;

		if (state < k) {
			count += 1;
		}
	// cout << "state: " << state << '\n';
	}

	return count;
}

int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m >> k;
		vector<int> house;
		int x;
		for (int j = 0; j < n; j++) {
			cin >> x;
			house.push_back(x);
		}
		cout << sol(house) << '\n';
	}
}
