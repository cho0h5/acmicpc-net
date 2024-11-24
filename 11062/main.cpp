#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int t, n;
int ns[1000];
pair<int, int> dp[1000][1000];

void print_dp() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "(" << dp[i][j].first << ", " << dp[i][j].second << ")" << '\t';
        }
        cout << '\n';
    }
}

int sol() {
    for (int c = 1; c < n; c++) {
        for (int r = c - 1; r >= 0; r--) {
            char turn;
            if ((c - r) % 2 != n % 2) {
                turn = 'g';
            } else {
                turn = 'm';
            }

            if (turn == 'g') {
                const int c1 = dp[r][c - 1].first + ns[c];
                const int c2 = dp[r + 1][c].first + ns[r];

                if (c1 > c2) {
                    dp[r][c] = {c1, dp[r][c - 1].second};
                } else {
                    dp[r][c] = {c2, dp[r + 1][c].second};
                }
            } else {
                const int c1 = dp[r][c - 1].second + ns[c];
                const int c2 = dp[r + 1][c].second + ns[r];

                if (c1 > c2) {
                    dp[r][c] = {dp[r][c - 1].first, c1};
                } else {
                    dp[r][c] = {dp[r + 1][c].first, c2};
                }
            }
        }
    }
    // cout << "a: " << dp[0][n - 1].first << '\n';
    // cout << "b: " << dp[0][n - 1].second << '\n';
    return dp[0][n - 1].first;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> ns[j];
            if (n % 2 == 0) {
                dp[j][j] = {0, ns[j]};
            } else {
                dp[j][j] = {ns[j], 0};
            }
        }
        cout << sol() << '\n';
        // print_dp();
    }
}
