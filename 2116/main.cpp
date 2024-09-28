#include <iostream>

using namespace std;

int dices[10000][6];
int n;

int find_face(int dice_i, int num) {
	for (int i = 0; i < 6; i++) {
		if (dices[dice_i][i] == num) {
			return i;
		}
	}

	return -1;
}

int opposite_face[6] = {5, 3, 4, 1, 2, 0};

int get_maximum_side_value(int dice_i, int down_face) {
	switch (down_face) {
		case 0:
		case 5:
			return max(max(dices[dice_i][1], dices[dice_i][2]),
					max(dices[dice_i][3], dices[dice_i][4]));
		case 1:
		case 3:
			return max(max(dices[dice_i][0], dices[dice_i][2]),
					max(dices[dice_i][4], dices[dice_i][5]));
		case 2:
		case 4:
			return max(max(dices[dice_i][0], dices[dice_i][1]),
					max(dices[dice_i][3], dices[dice_i][5]));
		default:
			return -1;
	}
}

int sol(int start_face) {
	int sum = get_maximum_side_value(0, start_face);
	// cout << "debug: " << sum << ", " << start_face << '\n';

	for (int i = 1; i < n; i++) {
		const int prev_up_face = opposite_face[start_face];
		const int prev_up_value = dices[i - 1][prev_up_face];
		const int curr_down_face = find_face(i, prev_up_value);

		// cout << "debug: " << get_maximum_side_value(i, curr_down_face) << ", " << curr_down_face << '\n';
		sum += get_maximum_side_value(i, curr_down_face);
		start_face = curr_down_face;
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> dices[i][j];
		}
	}

	int maximum = 0;
	for (int i = 0; i < 6; i++) {
		maximum = max(maximum, sol(i));
		// cout << '\n';
	}

	cout << maximum << '\n';
}
