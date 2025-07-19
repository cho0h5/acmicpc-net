#include <iostream>
#include <utility>

using namespace std;
typedef pair<int, int> ii;

int n, m, l;
ii dp[101][301][301];
int count[101][301][301];

void sol() {
    for (int i = 1; i <= n; i++) {
        int cheese, fries;
        cin >> cheese >> fries;

        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= l; k++) {
                if (j - cheese < 0 || k - fries < 0) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    count[i][j][k] = count[i - 1][j][k];
                    continue;
                }

                ii &state = dp[i - 1][j - cheese][k - fries];
                if (state.first + cheese <= m && state.second + fries <= l) {
                    if (count[i - 1][j - cheese][k - fries] + 1 > count[i - 1][j][k]) {
                        dp[i][j][k].first = state.first + cheese;
                        dp[i][j][k].second = state.second + fries;
                        count[i][j][k] = count[i - 1][j- cheese][k - fries] + 1;
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                        count[i][j][k] = count[i - 1][j][k];
                    }
                    continue;
                }

                dp[i][j][k] = dp[i - 1][j][k];
                count[i][j][k] = count[i - 1][j][k];
                continue;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> l;
    sol();

    printf("%d\n", count[n][m][l]);
}
