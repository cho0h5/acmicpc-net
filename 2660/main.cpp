#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>

#define INF 999999999

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void print_graph(int n, const vector<vector<int>> graph) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	fastio();
	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		graph[i][i] = 0;
	}
	while (1) {
		int x, y;
		cin >> x >> y;
		if (x == -1)
			break;
		graph[x - 1][y - 1] = 1;
		graph[y - 1][x - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				int minn = min(graph[i][j], graph[i][k] + graph[k][j]);
				graph[i][j] = minn;
				graph[j][i] = minn;
			}
		}
	}
	// print_graph(n, graph);

	int minn = INF;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int maxx = 0;
		for (int j = 0; j < n; j++) {
			maxx = max(maxx, graph[i][j]);
		}
		minn = min(minn, maxx);
		m.insert(make_pair(i, maxx));
	}

	vector<int> can;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second == minn) {
			can.push_back(it->first);
		}
	}
	cout << minn << ' ' << can.size() << '\n';
	for (int i = 0; i < (int)can.size(); i++) {
		cout << can[i] + 1 << ' ';
	}
	cout << '\n';
}
