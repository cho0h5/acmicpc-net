#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> dp1;
vector<int> dp2;

void back(int i, int target) {
	if (target < 0) return ;

	if (dp2[i] == target) {
		back(i - 1, target - 1);
		cout << arr[i] << ' ';
	} else {
		back(i - 1, target);
	}

}

int main() {
	int n;
	cin >> n;
	arr.reserve(n);
	dp2.reserve(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		if (dp1.empty() || dp1.back() < arr[i]) {
			dp2.push_back(dp1.size());
			dp1.push_back(arr[i]);
		} else {
			auto it = lower_bound(dp1.begin(), dp1.end(), arr[i]);
			dp2.push_back(distance(dp1.begin(), it));
			*it = arr[i];
		}
	}
	cout << dp1.size() << '\n';
	back(n - 1, dp1.size() - 1);
	cout << '\n';
}
