#include <iostream>

using namespace std;

long long dp[101] = {0, 1, 1, 1, 2, 2};
int t, n;

long long re(int n) {
    if (dp[n] != 0) return dp[n];
    dp[n] = re(n - 1) + re(n - 5);
    return re(n - 1) + re(n - 5);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        cout << re(n) << "\n";
    }
}
