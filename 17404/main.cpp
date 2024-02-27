#include <iostream>
#include <algorithm>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int n;
int cost[1000][3];
int acc[1000][3];

#define INF 99999999

void down_dp(int min_i) {
	acc[0][0] = INF;
	acc[0][1] = INF;
	acc[0][2] = INF;
	acc[0][min_i] = cost[0][min_i];

	for (int i = 1; i < n; i++) {
		acc[i][0] = min(acc[i - 1][1], acc[i - 1][2]) + cost[i][0];
		acc[i][1] = min(acc[i - 1][2], acc[i - 1][0]) + cost[i][1];
		acc[i][2] = min(acc[i - 1][0], acc[i - 1][1]) + cost[i][2];
	}
}


void up_dp(int min_i) {
	acc[n - 1][0] = INF;
	acc[n - 1][1] = INF;
	acc[n - 1][2] = INF;
	acc[n - 1][min_i] = cost[n - 1][min_i];

	for (int i = n - 2; i >= 0; i--) {
		acc[i][0] = min(acc[i + 1][1], acc[i + 1][2]) + cost[i][0];
		acc[i][1] = min(acc[i + 1][2], acc[i + 1][0]) + cost[i][1];
		acc[i][2] = min(acc[i + 1][0], acc[i + 1][1]) + cost[i][2];
	}
}

void print_acc() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << acc[i][0] <<' ';
		cout << acc[i][1] <<' ';
		cout << acc[i][2] <<'\n';
	}
	cout << '\n';
}

int get_min_index() {
	int min_i = 0;
	int min = acc[0][0];
	for (int i = 1; i < 3; i++) {
		if (min > acc[0][i]) {
			min = acc[0][i];
			min_i = i;
		}
	}
	return min_i;
}

int main() {
	fastio();
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}

	int min_cost = INF;
	for (int i = 0; i < 3; i++) {
		int min_i = i;
		down_dp(min_i);
		for (int i = 0; i < 3; i++) {
			if (i != min_i)
				min_cost = min(min_cost, acc[n - 1][i]);
		}
		// print_acc();
		up_dp(min_i);
		// print_acc();
		for (int i = 0; i < 3; i++) {
			if (i != min_i)
				min_cost = min(min_cost, acc[0][i]);
		}
	}
	cout << min_cost << '\n';
}
