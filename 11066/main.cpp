#include <iostream>

#define MAXIMUM 21474

using namespace std;

int dp[500][500];
int costs[500];
int k;

int get_cost(const int x, const int y) {
	if (x == y) {
		return costs[x];
	}
	return dp[x][y];
}

void print_dp() {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			cout << dp[i][j] << '\t';
		}
		cout << '\n';
	}
}

int sol() {
	for (int j = 0; j < k; j++) {
		for (int i = j - 1; i >= 0; i--) {
			// cout << "(" << i << ", " << j << ")\n";
			for (int l = 0; l < j - i; l++) {
				const int cost_a = get_cost(i, i + l);
				const int cost_b = get_cost(i + 1 + l, j);

				dp[i][j] = min(dp[i][j], cost_a + cost_b + dp[i][i + l] + dp[i + 1 + l][j]);
			}
			// cout << dp[i][j] << '\n';
		}
		// cout << '\n';
	}

	print_dp();

	return dp[0][k - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> k;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				dp[i][j] = MAXIMUM;
			}
		}
		cout << dp[0][1] << '\n';
		for (int i = 0; i < k; i++) {
			dp[i][i] = 0;
			cin >> costs[i];
		}
		cout << sol() << '\n';
	}

	return 0;
}
