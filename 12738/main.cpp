#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int> arr;
vector<int> dp;

int main() {
	fastio();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		if (dp.empty() || dp.back() < arr[i]) {
			dp.push_back(arr[i]);
		} else {
			auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
			*it = arr[i];
		}
	}
	cout << dp.size() << '\n';
}
