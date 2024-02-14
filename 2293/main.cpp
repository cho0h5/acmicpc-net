#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> coins;
int dp[10001];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		coins.push_back(c);
	}

	dp[0] = 1;
	for (int j = 0; j < n; j++)
		for (int i = coins[j]; i <= k; i++)
			dp[i] += dp[i - coins[j]];

	cout << dp[k] << '\n';
}
