#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> coins;
int dp[10001][100];
using namespace std;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if (c > 10000)
            continue;
        auto it = find(coins.begin(), coins.end(), c);
        if (it == coins.end())
            coins.push_back(c);
    }

    sort(coins.begin(), coins.end());
    for (int i = 0; i < coins.size(); i++) {
        // printf("debug: %d\n", coins[i]);
        dp[coins[i]][i] = 1;
    }

    if (coins.empty())
    {
        printf("-1\n");
        return 0;
    }
    for (int i = coins[0] + 1; i <= k; i++) {
        for (int j = 0; j < coins.size(); j++) {

            if (i - coins[j] > 0) {
                int origin_sum = 0;
                for (int l = 0; l < coins.size(); l++)
                    origin_sum += dp[i][l];
                int new_sum = 0;
                for (int l = 0; l < coins.size(); l++)
                    new_sum += dp[i - coins[j]][l];
                if (new_sum != 0 && (origin_sum == 0 || new_sum < origin_sum)) {
                    for (int l = 0; l < coins.size(); l++)
                        dp[i][l] = dp[i - coins[j]][l];
                    dp[i][j] += 1;
                }
            }
        }
    }

//	for (int i = 0; i <= k; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << dp[i][j] << ' ';
//		}
//		cout << '\n';
//	}

    int sm = 0;
    for (int i = 0; i < n; i++)
        sm += dp[k][i];
    if (sm == 0)
        cout << "-1\n";
    else
        cout << sm << '\n';
}