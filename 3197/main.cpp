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

int r, c;
int vst[1500][1500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int is_out_bound(int i, int j) {
	if (i < 0 || i >= r || j < 0 || j >= c)
		return 1;
	return 0;
}

int main() {
	fastio();

	// input
	cin >> r >> c;
	vector<vector<int>> lake(r, vector<int>(c));
	vector<pair<int, int>> swans;
	input_lake(r, c, lake, swans);
}
