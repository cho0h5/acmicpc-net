#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
pair<int, int> xs[100000];
pair<int, int> ys[100000];
pair<int, int> zs[100000];
vector<tuple<int, int, int>> edges;
int parents[100000];

int find(const int node) {
	if (parents[node] == node) return node;
	return parents[node] = find(parents[node]);
}

void merge(const int a, const int b) {
	const int pa = find(a);
	const int pb = find(b);

	parents[pb] = pa;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		parents[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		xs[i] = {x, i};
		ys[i] = {y, i};
		zs[i] = {z, i};
	}
	sort(xs, &xs[n]);
	sort(ys, &ys[n]);
	sort(zs, &zs[n]);

	for (int i = 0; i < n - 1; i++) {
		const int p = xs[i].second;
		const int q = xs[i + 1].second;
		const int cost = abs(xs[i].first - xs[i + 1].first);
		edges.push_back({cost, p, q});
	}
	for (int i = 0; i < n - 1; i++) {
		const int p = ys[i].second;
		const int q = ys[i + 1].second;
		const int cost = abs(ys[i].first - ys[i + 1].first);
		edges.push_back({cost, p, q});
	}
	for (int i = 0; i < n - 1; i++) {
		const int p = zs[i].second;
		const int q = zs[i + 1].second;
		const int cost = abs(zs[i].first - zs[i + 1].first);
		edges.push_back({cost, p, q});
	}

	sort(edges.begin(), edges.end());

	int total_cost = 0;
	for (auto edge : edges) {
		auto [cost, p, q] = edge;
		if (find(p) == find(q)) continue;

		total_cost += cost;
		merge(p, q);
	}

	cout << total_cost << '\n';
}
