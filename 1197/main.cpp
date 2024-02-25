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

int v, e;
vector<tuple<int, int, int>> edges;
int table[10001];

int parent(int node) {
	if (node == table[node])
		return node;
	return parent(table[node]);
}

int main() {
	fastio();

	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		table[i] = i;
	}
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back(make_tuple(c, a, b));
	}
	sort(edges.begin(), edges.end());

	int total_cost = 0;
	for (auto it = edges.begin(); it != edges.end(); it++) {
		auto [cost, a, b] = *it;
		int pa = parent(a);
		int pb = parent(b);
		if (pa != pb) {
			total_cost += cost;
			if (pa < pb) table[pb] = pa;
			else table[pa] = pb;
		}
	}
	cout << total_cost << '\n';
}
