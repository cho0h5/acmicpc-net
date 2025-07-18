#include <iostream>
#include <vector>

using namespace std;

int max_distance;
int n;

int roads[101];
int acc[101];
int ns[100];
int dp[102];
int prv[102];

void sol() {
    dp[0] = 0;
    prv[0] = -1;

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j < i; j++) {
            // If possible, then update and break;
            if (acc[i] - acc[j] <= max_distance) {
                int cand = 0;
                if (j != 0) {
                     cand = dp[j] + ns[j - 1];
                }

                if (dp[i] >= cand) {
                    dp[i] = cand;
                    prv[i] = j;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> max_distance;
    cin >> n;
    acc[0] = 0;
    for (int i = 0; i < n + 1; i++) {
        cin >> roads[i];
        acc[i + 1] = acc[i] + roads[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> ns[i];
    }
    for (int i = 0; i < n + 2; i++) {
        dp[i] = 2147483647;
    }


    sol();

    ///
//    for (int i = 0; i < n + 2; i++) {
//        printf("%d ", acc[i]);
//    }
//    printf("\n");
//    for (int i = 0; i < n + 2; i++) {
//        printf("%d ", dp[i]);
//    }
//    printf("\n");
//    for (int i = 0; i < n + 2; i++) {
//        printf("%d ", prv[i]);
//    }
//    printf("\n");
    ///

    printf("%d\n", dp[n + 1]);

    vector<int> path;
    int node = prv[n + 1];

    if (node == 0) {
        printf("0\n");
        return 0;
    }

    path.push_back(node);
    while (1) {
        if (node == -1) {
            break;
        }
        node = prv[node];
        if (node == 0 || node == -1) {
            break;
        }
        path.push_back(node);
    }
    printf("%ld\n", path.size());
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}
