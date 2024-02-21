#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input_lake(int &r, int &c, vector<vector<int>> &lake, vector<pair<int, int>> &swans) {
	for (int i = 0; i < r; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < line.size(); j++) {
			if (line[j] == '.') {
				lake[i][j] = -1;
			} else if (line[j] == 'L') {
				lake[i][j] = -1;
				swans.push_back(make_pair(i, j));
			} else {
				lake[i][j] = 0;
			}
		}
	}
}

void print_lake(vector<vector<int>> &lake) {
	for (int i = 0; i < lake.size(); i++) {
		for (int j = 0; j < lake[i].size(); j++) {
			cout << lake[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_swans(vector<pair<int, int>> &swans) {
	cout << "swan0: " << swans[0].first << ' ' << swans[0].second << '\n';
	cout << "swan1: " << swans[1].first << ' ' << swans[1].second << '\n';
	cout << '\n';
}

int r, c;
int vst[1500][1500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bzero_vst() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			vst[i][j] = 0;
		}
	}
}

int is_out_bound(int i, int j) {
	if (i < 0 || i >= r || j < 0 || j >= c)
		return 1;
	return 0;
}

void color_lake_bfs(queue<pair<int, int>> &q, vector<vector<int>> &lake) {
	while (!q.empty()) {
		auto e = q.front();
		q.pop();
		int i = e.first;
		int j = e.second;
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (is_out_bound(nx, ny)) continue;
			if (vst[nx][ny] == 1) continue;
			vst[nx][ny] = 1;
			if (lake[nx][ny] == 0) continue;
			lake[nx][ny] = lake[i][j];
			q.push(make_pair(nx, ny));
		}
	}
}

void color_lake(vector<vector<int>> &lake) {
	queue<pair<int, int>> q;
	int count = 1;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (lake[i][j] == -1) {
				vst[i][j] = 1;
				lake[i][j] = count;
				q.push(make_pair(i, j));
				color_lake_bfs(q, lake);
				count++;
			}
		}
	}
}

int is_swan_on_same_lake(const vector<vector<int>> &lake, vector<pair<int, int>> &swans) {
	int swan1_x = swans[0].first;
	int swan1_y = swans[0].second;
	int swan2_x = swans[1].first;
	int swan2_y = swans[1].second;
	return lake[swan1_x][swan1_y] == lake[swan2_x][swan2_y];
}

void shaving_ice_bfs(vector<vector<int>> &lake, queue<pair<int, int>> &q);

void occupation(vector<vector<int>> &lake, int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	int vst2[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			vst2[i][j] = 0;
		}
	}
	while (!q.empty()) {
		auto e = q.front();
		q.pop();
		int i = e.first;
		int j = e.second;
		vst2[i][j] = 1;
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (is_out_bound(nx, ny)) continue;
			if (lake[nx][ny] == 0) continue;
			if (vst2[nx][ny] == 1) continue;
			vst2[nx][ny] = 1;
			lake[nx][ny] = lake[i][j];
			q.push(make_pair(nx, ny));
		}
	}
}

void assert_ice(vector<vector<int>> &lake, int i, int j) {
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (is_out_bound(nx, ny)) continue;
//		if (i == 5 && j == 0)
//		{
//			cout << "assert!\n";
//			cout << lake[i][j] << '\n';
//			cout << lake[nx][ny] << '\n';
//		}
		if (lake[nx][ny] != 0 && lake[nx][ny] != lake[i][j]) {
			if (vst[nx][ny] == 1) {
				occupation(lake, nx, ny);
				continue;
			}
			vst[nx][ny] = 1;
			queue<pair<int, int>> q;
			lake[nx][ny] = lake[i][j];
			q.push(make_pair(nx, ny));
			shaving_ice_bfs(lake, q);
		}
	}
}

void shaving_ice_bfs(vector<vector<int>> &lake, queue<pair<int, int>> &q) {
	while (!q.empty()) {
		auto e = q.front();
		q.pop();
		int i = e.first;
		int j = e.second;
		vst[i][j] = 1;
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (is_out_bound(nx, ny)) continue;
			if (vst[nx][ny] == 1) continue;
			vst[nx][ny] = 1;

			if (lake[nx][ny] == 0) {
				lake[nx][ny] = lake[i][j];
				assert_ice(lake, nx, ny);
				continue;
			}
			lake[nx][ny] = lake[i][j];
			q.push(make_pair(nx, ny));
		}
	}
}

void shaving_ice(vector<vector<int>> &lake) {
	bzero_vst();
	queue<pair<int, int>> q;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (lake[i][j] != 0 && vst[i][j] != 1) {
				q.push(make_pair(i, j));
				shaving_ice_bfs(lake, q);
			}
		}
	}
}

int main() {
	fastio();

	// input
	cin >> r >> c;
	vector<vector<int>> lake(r, vector<int>(c));
	vector<pair<int, int>> swans;
	input_lake(r, c, lake, swans);
	// print_swans(swans);

	int count = 0;
	color_lake(lake);
	// print_lake(lake);
	if (is_swan_on_same_lake(lake, swans)) {
		cout << count << '\n';
		return 0;
	}

	while (1) {
		count++;
		shaving_ice(lake);
		// print_lake(lake);
		if (is_swan_on_same_lake(lake, swans)) {
			cout << count << '\n';
			return 0;
		}
	}
}
