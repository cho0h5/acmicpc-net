#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void push(int position, int score, vector<pair<int, int>> &dp, int w) {
	if (position > w)
		return;
	if ((int)dp.size() <= position) {
		dp.push_back(make_pair(position, score));
	} else {
		dp[position].second = max(dp[position].second, score);
	}

}

void print_dp(const vector<pair<int, int>> &dp) {
	cout << "---------\n";
	for (auto is = dp.begin(); is != dp.end(); is++) {
		cout << is->first << ' ' << is->second << '\n';
	}
	cout << "---------\n";
}

void solve(const vector<int> &tree, const int w) {
	vector<pair<int, int>> dp;

	dp.push_back(make_pair(0, tree[0] == 1));
	if (w > 0) {
		dp.push_back(make_pair(1, tree[0] == 2));
	}
	auto it = tree.begin() + 1;
	// print_dp(dp);
	for (; it != tree.end(); it++) {
		int prev = *(it - 1);
		int curr = *it;

		for (auto is = dp.begin(); is != dp.end(); is++) {
			is->second += is->first % 2 != curr % 2;
		}
		if (prev != curr) {
			// cout << "chance\n";
			for (int j = 0; j < (int)dp.size(); j++) {
				if (dp[j].first % 2 != prev % 2) {
					push(dp[j].first + 1, dp[j].second + 1, dp, w);

				}
			}
		}
		// print_dp(dp);
	}

	int maxx = 0;
	for (auto is = dp.begin(); is != dp.end(); is++) {
		// cout << is->first << ' ' << is->second << '\n';
		maxx = max(maxx, is->second);
	}
	cout << maxx << '\n';
}

int main() {
	fastio();

	int t, w;
	cin >> t >> w;
	vector<int> tree;
	for (int i = 0; i < t; i++) {
		int x;
		cin >> x;
		tree.push_back(x);
	}

	solve(tree, w);
}
