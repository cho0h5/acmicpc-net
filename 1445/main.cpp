#include <iostream>
#include <tuple>
#include <utility>
#include <queue>

using namespace std;
using ii = pair<int, int>;
using iiii = tuple<int, int, int, int>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

char world[50][50];
pair<int, int> costs[50][50];
int n, m;
priority_queue<iiii, vector<iiii>, greater<iiii>> pq;
pair<int, int> s;

char get_world(const int x, const int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return '-';
	}
	return world[x][y];
}

iiii make_pq_node(const int cost_through, const int cost_near, const int x, const int y) {
	int additional_cost_through = 0;
	int additional_cost_near = 0;

		// cout << "wtf: " << (int)get_world(x, y) << '\n';
	if (get_world(x, y) == 'g') {
		additional_cost_through += 1;
	}
	for (int i = 0; i < 4; i++) {
		if (get_world(x + dx[i], y + dy[i]) == 'g') {
			additional_cost_near += 1;
		}
	}
	if (get_world(x, y) == 'F') {
		additional_cost_near = 0;
	}
	
	return {cost_through + additional_cost_through,
		cost_near + additional_cost_near,
		x, y};
}

void print_costs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "(" << costs[i][j].first << ",\t" << costs[i][j].second << ")\t";
		}
		cout << '\n';
	}
	cout << '\n';
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string buf;
		cin >> buf;
		for (int j = 0; j < m; j++) {
			world[i][j] = buf[j];
			if (buf[j] == 'S') {
				s = {i, j};
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			costs[i][j] = {999, 999};
		}
	}
	
	pq.push({0, 0, s.first, s.second});
	costs[s.first][s.second] = {0, 0};
}

void print_world() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << world[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

ii sol() {
	while (pq.size()) {
		int c_t, c_n, x, y;
		tie(c_t, c_n, x, y) = pq.top();
		pq.pop();

		// cout << "pop: " << c_t << ' ' << c_n << ' ' << x << ' ' << y << '\n';
		for (int i = 0; i < 4; i++) {
			int nc_t, nc_n;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (get_world(nx, ny) == '-') {
				continue;
			}
			tie(nc_t, nc_n, nx, ny) = make_pq_node(c_t, c_n, nx, ny);

			if (costs[nx][ny].first > nc_t ||
					(costs[nx][ny].first == nc_t && costs[nx][ny].second > nc_n)) {
				if (get_world(nx, ny) == 'F') {
					return {nc_t, nc_n};
				}
				costs[nx][ny] = {nc_t, nc_n};
				pq.push({nc_t, nc_n, nx, ny});
			}
		}
		// print_costs();
	}
	return {-1, -1};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	// print_world();

	const ii result = sol();

	cout << result.first << ' ' << result.second << '\n';
}
