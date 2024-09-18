#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[10][10];
int n;

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

unsigned long result;
vector<pair<int, int>> bs;

bool check() {
	auto [x, y] = bs.back();

	for (int i = 0; i < bs.size() - 1; i++) {
		const int p = bs[i].first;
		const int q = bs[i].second;
		if (abs(x - p) == abs(y - q)) {
			return false;
		}
	}
	return true;
}

int next_pos(const int pos) {
	if (n % 2 == 1) return pos + 2;

	const int i = pos / n;
	const int j = pos % n;

	if (j == n - 1) return pos + 1;
	if (j == n - 2) return pos + 3;
	return pos + 2;
}

void print_bs() {
	for (auto &it : bs) {
		cout << it.first << ' ' << it.second << ", ";
	}
	cout << '\n';
}

void sol(const int pos) {
	if (pos >= n * n) return;
	// cout << "pos: " << pos << '\n';
	// print_bs();

	const int i = pos / n;
	const int j = pos % n;

	if (board[i][j] == 0) {
		sol(next_pos(pos));
		return;
	}

	bs.push_back({i, j});
	if (check()) {
		result = max(result, bs.size());
		sol(next_pos(pos));
	}
	bs.pop_back();
	sol(next_pos(pos));
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	// print();
   	sol(0);
	int tmp = result;
	result = 0;
	sol(1);
	cout << tmp + result << '\n';
}
