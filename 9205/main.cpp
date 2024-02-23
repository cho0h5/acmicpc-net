#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

#define INF 999999999

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<int, int> > points;
int graph[102][102];

void testcase() {
	int n;
	cin >> n;
	n += 2;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		points.push_back(make_pair(x, y));
		for (int j = 0; j < n; j++) {
			graph[i][j] = INF;
		}
	}
	for (int i = 0; i < n; i++) {
		graph[i][i] = 1;
		for (int j = 0; j < n; j++) {
			int distance_x = abs(points[i].first - points[j].first);
			int distance_y = abs(points[i].second - points[j].second);
			int distance = distance_x + distance_y;
			if (distance <= 1000) {
				graph[i][j] = 1;
				graph[j][i] = 1;
			}
		}
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
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << graph[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	points.clear();
	if (graph[0][n - 1] != INF) {
		cout << "happy\n";
	} else {
		cout << "sad\n";
	}
}

int main() {
	fastio();

	int t;
	cin >> t;
	while (t--)
		testcase();
}
