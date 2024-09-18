#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

int p[100001];
int root(const int x) {
	if (p[x] == x) return x;
	return p[x] = root(p[x]);
}
bool merge(const int x, const int y) {
	const int px = root(x);
	const int py = root(y);

	if (px == py) return false;

	p[py] = px;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}

	vector<tuple<int, int, int>> edges;
	edges.reserve(m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({c, a, b});
	}
	sort(edges.begin(), edges.end());

	int total_cost = 0;
	int maximum = 0;
	for (auto &edge: edges) {
		auto [c, a, b] = edge;
		if (merge(a, b)) {
			total_cost += c;
			maximum = max(maximum, c);
		}
	}
	cout << total_cost - maximum << '\n';
}
