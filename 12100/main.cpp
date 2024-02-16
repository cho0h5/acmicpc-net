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

void print_map(vector<vector<int>> &map) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.size(); j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void swipe_left_line(vector<vector<int>> &map, int index) {
	int top_i = 0;
	int top = map[index][0];
	for (int i = 1; i < map.size(); i++) {
		if (map[index][i] != 0 && map[index][i] == top)
		{
			map[index][top_i] = map[index][i] << 1;
			top_i += 1;
			top = 0;
		} else if (map[index][i] != 0 && top != 0 && map[index][i] != top) {
			map[index][top_i] = top;
			top_i += 1;
			top = map[index][i];
		} else if (top == 0 && map[index][i] != 0) {
			top = map[index][i];
		}
	}
	map[index][top_i++] = top;
	for (; top_i < map.size(); top_i++) {
		map[index][top_i] = 0;
	}
}

void swipe_left(vector<vector<int>> &map) {
	for (int i = 0; i < map.size(); i++)
		swipe_left_line(map, i);
}

void swipe_right_line(vector<vector<int>> &map, int index) {
	int top_i = map.size() - 1;
	int top = map[index][top_i];
	for (int i = map.size() - 2; i >= 0; i--) {
		if (map[index][i] != 0 && map[index][i] == top)
		{
			map[index][top_i] = map[index][i] << 1;
			top_i -= 1;
			top = 0;
		} else if (map[index][i] != 0 && top != 0 && map[index][i] != top) {
			map[index][top_i] = top;
			top_i -= 1;
			top = map[index][i];
		} else if (top == 0 && map[index][i] != 0) {
			top = map[index][i];
		}
	}
	map[index][top_i--] = top;
	for (; top_i >= 0; top_i--) {
		map[index][top_i] = 0;
	}
}

void swipe_right(vector<vector<int>> &map) {
	for (int i = 0; i < map.size(); i++)
		swipe_right_line(map, i);
}

void swipe_up_line(vector<vector<int>> &map, int index) {
	int top_i = 0;
	int top = map[0][index];
	for (int i = 1; i < map.size(); i++) {
		if (map[i][index] != 0 && map[i][index] == top)
		{
			map[top_i][index] = map[i][index] << 1;
			top_i += 1;
			top = 0;
		} else if (map[i][index] != 0 && top != 0 && map[i][index] != top) {
			map[top_i][index] = top;
			top_i += 1;
			top = map[i][index];
		} else if (top == 0 && map[i][index] != 0) {
			top = map[i][index];
		}
	}
	map[top_i++][index] = top;
	for (; top_i < map.size(); top_i++) {
		map[top_i][index] = 0;
	}
}

void swipe_up(vector<vector<int>> &map) {
	for (int i = 0; i < map.size(); i++)
		swipe_up_line(map, i);
}

void swipe_down_line(vector<vector<int>> &map, int index) {
	int top_i = map.size() - 1;
	int top = map[top_i][index];
	for (int i = map.size() - 2; i >= 0; i--) {
		if (map[i][index] != 0 && map[i][index] == top)
		{
			map[top_i][index] = map[i][index] << 1;
			top_i -= 1;
			top = 0;
		} else if (map[i][index] != 0 && top != 0 && map[i][index] != top) {
			map[top_i][index] = top;
			top_i -= 1;
			top = map[i][index];
		} else if (top == 0 && map[i][index] != 0) {
			top = map[i][index];
		}
	}
	map[top_i--][index] = top;
	for (; top_i >= 0; top_i--) {
		map[top_i][index] = 0;
	}
}

void swipe_down(vector<vector<int>> &map) {
	for (int i = 0; i < map.size(); i++)
		swipe_down_line(map, i);
}

int find_max(vector<vector<int>> &map) {
	int maxx = 0;

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.size(); j++) {
			maxx = max(maxx, map[i][j]);
		}
	}
	return maxx;
}

int backtracking(vector<vector<int>> &map, int step) {
	if (step == 0) {
		// print_map(map);
		return find_max(map);
	}

	int maxx = 0;
	vector<vector<int>> map1 = map;
	swipe_right(map1);
	maxx = max(maxx, backtracking(map1, step - 1));

	vector<vector<int>> map2 = map;
	swipe_down(map2);
	maxx = max(maxx, backtracking(map2, step - 1));

	vector<vector<int>> map3 = map;
	swipe_left(map3);
	maxx = max(maxx, backtracking(map3, step - 1));

	vector<vector<int>> map4 = map;
	swipe_up(map4);
	maxx = max(maxx, backtracking(map4, step - 1));
	return maxx;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	fastio();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	// print_map(map);
	int maxx = backtracking(map, 5);
	cout << maxx << '\n';
}
