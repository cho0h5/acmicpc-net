#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int count;
    int step[301];
    step[0] = 0;
    int dp[301][2];
    dp[0][0] = 0;
    dp[0][1] = 0;

    scanf("%d", &count);
    for (int i = 1; i <= count; i++) {
        scanf("%d", &step[i]);
    }

    if (count >= 1) {
        dp[1][0] = step[1];
        dp[1][1] = step[1];
    }
    for (int i = 2; i <= count; i++) {
        dp[i][0] = dp[i - 1][1] + step[i];
        dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + step[i];
    }

    printf("%d\n", max(dp[count][0], dp[count][1]));

    return 0;
}
