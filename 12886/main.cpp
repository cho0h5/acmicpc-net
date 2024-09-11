#include <iostream>

using namespace std;

int is_possible_divide(int target, int a) {
	for (int i = 0; a <= 500; i++) {
		if (a == target) {
			return i;
		}
		a *= 2;
	}
	return -1;
}

void operation(int nums[2]) {
	const int a = nums[0];
	const int b = nums[1];

	if (a < b) {
		nums[0] = a * 2;
		nums[1] = b - a;
	} else {
		nums[0] = a - b;
		nums[1] = b * 2;
	}
}

bool sol2(int target1, int target2, int nums[2]) {
	// cout << target1 << ' ' << target2 << '\n';
	// cout << nums[0] << ' ' << nums[1] << '\n';

	const int initial = nums[0];

	if (nums[0] == target1 || nums[0] == target2) {
		return true;
	}

	operation(nums);
	while (initial != nums[0]) {
	// cout << nums[0] << ' ' << nums[1] << '\n';
		if (nums[0] == target1 || nums[0] == target2) {
			return true;
		}
		operation(nums);
	}
	return false;
}

bool sol3(int target, int nums[3]) {
	int minimum = nums[0];
	int min_i = 0;
	for (int i = 1; i < 3; i++) {
		if (minimum > nums[i]) {
			min_i = i;
			minimum = nums[i];
		}
	}

	int possibility = is_possible_divide(target, minimum);
	if (possibility == -1) {
		return false;
	}

	int num2[2];
	int j = 0;
	for (int i = 0; i < 3; i++) {
		if (min_i != i) {
			num2[j] = nums[i];
			j += 1;
		}
	}

	return sol2(target * 2 - minimum, target, num2);
}

int main() {
	int nums[3];
	cin >> nums[0] >> nums[1] >> nums[2];
	int sum = nums[0] + nums[1] + nums[2];

	int target = sum / 3;
	int remain =sum % 3;

	if (remain != 0) {
		cout << "0\n";
		return 0;
	}

	bool flag = false;
	int num2[3];
	int j = 0;
	for (int i = 0; i < 3; i++) {
		if (nums[i] == target) {
			flag = true;
		}
		else {
			num2[j] = nums[i];
			j += 1;
		}
	}
	if (flag) {
		cout << sol2(target, target, num2) << '\n';
		return 0;
	}

	cout << sol3(target, nums) << '\n';
}
