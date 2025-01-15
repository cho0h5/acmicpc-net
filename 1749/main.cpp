#include <iostream>

using namespace std;

long long n, m;
long long matrix[201][201];
long long dp[201][201];

void print_arr(long long matrix[][201]) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << '\n';
    }
    cout << '\n';
}

long long bf() {
    long long maximum = -203498752039487;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = i + 1; k <= n; k++) {
                for (int l = j + 1; l <= m; l++) {
                    long long subsum = dp[k][l] - dp[k][j] - dp[i][l] + dp[i][j];
                    maximum = max(maximum, subsum);
                }
            }
        }
    }
    return maximum;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i][j];
        }
    }
    // print_arr(matrix);
    // print_arr(dp);

    cout << bf() << '\n';
}
