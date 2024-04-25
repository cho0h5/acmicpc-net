#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int n, m;
tuple<int, int, int> graph[100001];
int parent[1001];

int getParent(int n) {
	if (n == parent[n]) {
		return n;
	}

	return parent[n] = getParent(parent[n]);
}

void unionn(int a, int b) {
	int parent_a = getParent(a);
	int parent_b = getParent(b);

	parent[parent_a] = parent_b;
}

int main() {
	fastio();
	for (int i = 0; i < 1001; i++) {
		parent[i] = i;
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[i] = {c, a, b};
	}
	sort(graph, graph + m);

	int cost = 0;
	for (auto edge: graph) {
		int c, a, b;
		tie(c, a, b) = edge;

		if (getParent(a) == getParent(b)) {
			continue;
		}
		unionn(a, b);
		cost += c;
	}
	cout << cost << '\n';
}
