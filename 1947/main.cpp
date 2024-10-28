#include <iostream>

using namespace std;

long long dp[1000001];
int n;

int main() {
	cin >> n;
	dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
		dp[i] %= 1000000000;
	}
	cout << dp[n] << '\n';
}
