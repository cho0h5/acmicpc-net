//
// Created by Youngho Cho on 2/11/24.
//

#include <iostream>

int n, k;
using namespace std;

long long dp[201];

int main() {
    cin >> n >> k;

    if (k == 1)
    {
        printf("1\n");
        return 0;
    }

    fill(dp, dp + n + 1, 1);
    for (int i = 0; i < k - 2; i++) {
        long long s = 0;
        for (int j = 0; j < n + 1; j++) {
            s += dp[j] % 1000000000;
            dp[j] = s;
        }
//        for (int j = 0; j < n + 1; j++)
//            cout << dp[j] << ' ';
//        cout << '\n';
    }
    long long s = 0;
    for (int j = 0; j < n + 1; j++)
        s += dp[j] % 1000000000;
    cout << s % 1000000000 << '\n';
}