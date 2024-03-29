#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int notebook[40][40];
int sticker[10][10];
int n, m, k;
int r, c;

int check_sticker1(int dx, int dy) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (notebook[dx + i][dy + j] == 1 && sticker[i][j] == 1)
				return 0;
		}
	}
	return 1;
}

int check_sticker2(int dx, int dy) {
	for (int i = 0; i < c; i++) {
		for (int j = r - 1; j >= 0; j--) {
//			cout << "notebookt: " << dx + i << ' ' << dy + r - 1 - j << ' ' << notebook[dx + i][dy + r - 1 - j] << '\n';
//			cout << "swicker: " <<j << ' ' << i << ' ' << sticker[j][i] << '\n';
			if (notebook[dx + i][dy + r - 1 - j] == 1 && sticker[j][i] == 1)
				return 0;
		}
	}
	return 1;
}

int check_sticker3(int dx, int dy) {
	for (int i = r - 1; i >= 0; i--) {
		for (int j = c - 1; j >= 0; j--) {
			if (notebook[dx + r - 1 - i][dy + c - 1 - j] == 1 && sticker[i][j] == 1)
				return 0;
		}
	}
	return 1;
}

int check_sticker4(int dx, int dy) {
	for (int i = c - 1; i >= 0; i--) {
		for (int j = 0; j < r; j++) {
			// cout << "notebookt: " << dx + c - 1 - i << ' ' << dy + j << ' ' << notebook[dx + c - 1 - i][dy + j] << '\n';
			// cout << "swicker: " <<j << ' ' << i << ' ' << sticker[j][i] << '\n';
			if (notebook[dx + c - 1 - i][dy + j] == 1 && sticker[j][i] == 1)
				return 0;
		}
	}
	return 1;
}

void fill_sticker1(int dx, int dy) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j] == 1)
				notebook[dx + i][dy + j] = 1;
		}
	}
}
void fill_sticker2(int dx, int dy) {
	for (int i = 0; i < c; i++) {
		for (int j = r - 1; j >= 0; j--) {
			if (sticker[j][i] == 1)
			{
				notebook[dx + i][dy + r - 1 - j] = 1;
			}
		}
	}
}

void fill_sticker3(int dx, int dy) {
	for (int i = r - 1; i >= 0; i--) {
		for (int j = c - 1; j >= 0; j--) {
			if (sticker[i][j] == 1)
				notebook[dx + r - 1 - i][dy + c - 1 - j] = 1;
		}
	}
}

void fill_sticker4(int dx, int dy) {
	for (int i = c - 1; i >= 0; i--) {
		for (int j = 0; j < r; j++) {
			if (sticker[j][i] == 1)
				notebook[dx + c - 1 - i][dy + j] = 1;
		}
	}
}

void print_notebook() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << notebook[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int fill1() {
	for (int dx = 0; dx <= n - r; dx++) {
		for (int dy = 0; dy <= m - c; dy++) {
			if (check_sticker1(dx, dy)) {
				// cout << "fill1: " << r << ' ' << c << '\n';
				fill_sticker1(dx, dy);
				// print_notebook();
				return 1;
			}
		}
	}
	return 0;
}

int fill2() {
	for (int dx = 0; dx <= n - c; dx++) {
		for (int dy = 0; dy <= m - r; dy++) {
			// cout << "fill2: " << dx << ' ' << dy << '\n';
			if (check_sticker2(dx, dy)) {
				// cout << "fill2\n";
				fill_sticker2(dx, dy);
				// print_notebook();
				return 1;
			}
		}
	}
	return 0;
}

int fill3() {
	for (int dx = 0; dx <= n - r; dx++) {
		for (int dy = 0; dy <= m - c; dy++) {
			if (check_sticker3(dx, dy)) {
				// cout << "fill3\n";
				fill_sticker3(dx, dy);
				// print_notebook();
				return 1;
			}
		}
	}
	return 0;
}

int fill4() {
	for (int dx = 0; dx <= n - c; dx++) {
		for (int dy = 0; dy <= m - r; dy++) {
			// cout << "fill4: " << dx << ' ' << dy << '\n';
			if (check_sticker4(dx, dy)) {
				// cout << "fill4\n";
				fill_sticker4(dx, dy);
				// print_notebook();
				return 1;
			}
		}
	}
	return 0;
}

int count_notebook() {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			count += notebook[i][j];
		}
	}
	return count;
}

int main() {
	fastio();

	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j];
			}
		}
		// cout << "target: " << r << ' ' << c << '\n';
		if (fill1()) continue;
		if (fill2()) continue;
		if (fill3()) continue;
		if (fill4()) continue;
	}
	cout << count_notebook() << '\n';
}
