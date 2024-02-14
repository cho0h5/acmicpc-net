#include <iostream>

using namespace std;

int n, m;
int map[1001][1001];
string line;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> line;
		for (int j = 1; j <= m; j++) {
			map[i][j] = line[j - 1] - '0';
		}
	}

	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != 0)
			{
				int m = min(map[i - 1][j], map[i - 1][j - 1]);
				m = min(m, map[i][j - 1]);
				map[i][j] = m + 1;
				maxx = max(map[i][j], maxx);
			}
		}
	}

//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= m; j++) {
//			cout << map[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	cout << maxx * maxx << '\n';
}
