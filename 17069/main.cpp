#include <iostream>

using namespace std;

long long board[32][32];
long long dp[32][32][3];
int n;

long long sol() {
	dp[0][1][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1) {
				continue;
			}
			if (j != 0) {
				dp[i][j][0] += dp[i][j - 1][0];
				dp[i][j][0] += dp[i][j - 1][2];
			}
			if (i != 0) {
				dp[i][j][1] += dp[i - 1][j][1];
				dp[i][j][1] += dp[i - 1][j][2];
			}
			if (i != 0 && j != 0) {
				if (board[i - 1][j] == 1 || board[i][j - 1]) {
					continue;
				}
				dp[i][j][2] += dp[i - 1][j - 1][0];
				dp[i][j][2] += dp[i - 1][j - 1][1];
				dp[i][j][2] += dp[i - 1][j - 1][2];
			}
		}
	}

	return dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	cout << sol() << '\n';
}
