#include <iostream>

using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int cost[1000][3];
int acc_cost[1000][3];
int t, a, b, c;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++) {
	cin >> a >> b >> c;
	cost[i][0] = a;
	cost[i][1] = b;
	cost[i][2] = c;
    }
    acc_cost[0][0] = cost[0][0];
    acc_cost[0][1] = cost[0][1];
    acc_cost[0][2] = cost[0][2];

    // solution
    for(int i = 1; i < t; i++) {
	acc_cost[i][0] = min(acc_cost[i-1][1], acc_cost[i-1][2]) + cost[i][0];
	acc_cost[i][1] = min(acc_cost[i-1][2], acc_cost[i-1][0]) + cost[i][1];
	acc_cost[i][2] = min(acc_cost[i-1][0], acc_cost[i-1][1]) + cost[i][2];
    }

    cout << min(min(acc_cost[t-1][0], acc_cost[t-1][1]), acc_cost[t-1][2]);
}
