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

int board[8][8];
int n, m;
vector<tuple<int, int, int, int>> cctv;	// x, y, cctv, i

void print_board(int n, int m, int board[8][8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_cctv(vector<tuple<int, int, int, int>> &cctv) {
	int x, y, c, i;

	for (auto it = cctv.begin(); it != cctv.end(); it++) {
		tie(x, y, c, i) = *it;
		cout << "cctv: " << x << ' ' << y << ' ' << c << ' ' << i << '\n';
	}
	cout << '\n';
}

int next(vector<tuple<int, int, int, int>> &cctv) {

	for (auto it = cctv.begin(); it != cctv.end(); it++) {
		if (get<2>(*it) == 6)
			continue;
		int &i = get<3>(*it);
		if (i < 3) {
			i += 1;
			return 1;
		} else {
			i = 0;
		}
	}
	return 0;
}

void capture1(int x, int y, int dir, int dp[8][8]) {
	if (dir == 0) {
		for (int i = x; i >= 0; i--) {
			if (board[i][y] == 6)
				break;
			dp[i][y] = 1;
		}
	} else if (dir == 1) {
		for (int i = y; i >= 0; i--) {
			if (board[x][i] == 6)
				break;
			dp[x][i] = 1;
		}
	} else if (dir == 2) {
		for (int i = x; i < n; i++) {
			if (board[i][y] == 6)
				break;
			dp[i][y] = 1;
		}
	} else {
		for (int i = y; i < m; i++) {
			if (board[x][i] == 6)
				break;
			dp[x][i] = 1;
		}
	}
}

void capture2(int x, int y, int dir, int dp[8][8]) {
	capture1(x, y, dir, dp);
	capture1(x, y, (dir + 2) % 4, dp);
}

void capture3(int x, int y, int dir, int dp[8][8]) {
	capture1(x, y, dir, dp);
	capture1(x, y, (dir + 3) % 4, dp);
}

void capture4(int x, int y, int dir, int dp[8][8]) {
	capture1(x, y, dir, dp);
	capture1(x, y, (dir + 1) % 4, dp);
	capture1(x, y, (dir + 2) % 4, dp);
}

void capture5(int x, int y, int dir, int dp[8][8]) {
	capture1(x, y, dir, dp);
	capture1(x, y, (dir + 1) % 4, dp);
	capture1(x, y, (dir + 2) % 4, dp);
	capture1(x, y, (dir + 3) % 4, dp);
}

void capture(vector<tuple<int, int, int, int>> &cctv, int dp[8][8]) {
	int x, y, c, i;

	for (auto it = cctv.begin(); it != cctv.end(); it++) {
		tie(x, y, c, i) = *it;
		switch (c) {
			case 1:
				capture1(x, y, i, dp);
				break;
			case 2:
				capture2(x, y, i, dp);
				break;
			case 3:
				capture3(x, y, i, dp);
				break;
			case 4:
				capture4(x, y, i, dp);
				break;
			case 5:
				capture5(x, y, i, dp);
				break;
			case 6:
				dp[x][y] = 1;
				break;
		}
	}
}

void clear_dp(int dp[8][8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = 0;
		}
	}
}

int count_dp(int dp[8][8]) {
	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			count += dp[i][j] == 0;
		}
	}
	return count;
}

int main() {
	int dp[8][8];
	fastio();

	// input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (1 <= board[i][j])
				cctv.push_back(make_tuple(i, j, board[i][j], 0));
		}
	}
	// print_board(n, m, board);
	
	// solution
	int minn = 100;
	int tmp;
	// print_cctv(cctv);
	clear_dp(dp);
	capture(cctv, dp);
	tmp = count_dp(dp);
	// cout << "tmp: " << tmp << '\n';
	if (tmp < minn) minn = tmp;
	// print_board(n, m, dp);
	while (next(cctv)) {
		// print_cctv(cctv);
		clear_dp(dp);
		capture(cctv, dp);
		tmp = count_dp(dp);
		// cout << "tmp: " << tmp << '\n';
		if (tmp < minn) minn = tmp;
		// print_board(n, m, dp);
	}
	cout << minn << '\n';
}
