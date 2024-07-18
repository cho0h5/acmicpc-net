#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> nums;

int more_closer_to_zero(int a, int b) {
	if (abs(a) < abs(b)) {
		return 0;
	} else {
		return 1;
	}
}

int sol() {
	int p = 0;
	int q = n - 1;
	int minimum = 2100000000;

	while (1) {
		if (p == q) break;

		if (more_closer_to_zero(minimum, nums[p] + nums[q])) {
			minimum = nums[p] + nums[q];
		}

		int candidate_a = nums[p] + nums[q - 1];
		int candidate_b = nums[p + 1] + nums[q];

		if (abs(candidate_a) < abs(candidate_b)) {
			q -= 1;
		} else {
			p += 1;
		}
	}

	return minimum;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}

	cout << sol() << '\n';
}

