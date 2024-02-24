#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int r, c;
int vst[1500][1500];
int vst2[1500][1500];
int lake[1500][1500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> swans;
queue<pair<int, int>> water;
queue<pair<int, int>> ice;
queue<pair<int, int>> swan;
queue<pair<int, int>> swan_tmp;

void input_lake() {
	for (int i = 0; i < r; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < line.size(); j++) {
			if (line[j] == '.') {
				lake[i][j] = 1;
				water.push({i, j});
				vst[i][j] = 1;
			} else if (line[j] == 'L') {
				lake[i][j] = 1;
				water.push({i, j});
				vst[i][j] = 1;
				swans.push_back(make_pair(i, j));
			} else {
				lake[i][j] = 0;
			}
		}
	}
	swan.push(swans[0]);
	vst2[swans[0].first][swans[0].second] = 1;
}

int is_out_bound(int i, int j) {
	if (i < 0 || i >= r || j < 0 || j >= c)
		return 1;
	return 0;
}

void print_lake() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << lake[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void melt() {
	while (water.size()) {
		auto [x, y] = water.front(); water.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (is_out_bound(nx, ny)) continue;
			if (vst[nx][ny] == 1) continue;
			vst[nx][ny] = 1;
			lake[nx][ny] = 1;
			ice.push({nx, ny});
		}
	}
	while (ice.size()) {
		water.push(ice.front()); ice.pop();
	}
}

int fly() {
	while (swan.size()) {
		auto [x, y] = swan.front(); swan.pop();
		if (x == swans[1].first && y == swans[1].second)
			return 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (is_out_bound(nx, ny)) continue;
			if (vst2[nx][ny] == 1) continue;
			vst2[nx][ny] = 1;
			if (lake[nx][ny] == 0) {
				swan_tmp.push({nx, ny});
			} else {
				swan.push({nx, ny});
			}
		}
	}
	while (swan_tmp.size()) {
		swan.push(swan_tmp.front()); swan_tmp.pop();
	}
	return 0;
}

int main() {
	fastio();
	int ret;

	// input
	cin >> r >> c;
	input_lake();

	int i = 0;
	while (1) {
		ret = fly();
		if (ret) {
			printf("%d\n", i);
			return 0;
		}
		// printf("ret: %d\n", ret);
		// print_lake();
		melt();
		i++;
	}
}
