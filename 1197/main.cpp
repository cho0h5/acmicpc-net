#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

vector<tuple<int, int, int> > edges;
int v;
int e;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int parents[10001];


int find(int a) {
	if (parents[a] == a) return a;
	parents[a] = find(parents[a]);
	return parents[a];
}
void merge(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa < pb) {
		parents[pb] = pa;
	} else {
		parents[pa] = pb;
	}
}

int sol() {
	int toal_cost = 0;

	for (auto &it: edges) {
		auto [cost, p, q] = it;

		if (find(p) != find(q)) {
			toal_cost += cost;
			merge(p, q);
		}
	}
	return toal_cost;
}

int main() {
	fastio();
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		parents[i] = i;
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({c, a, b});
	}
	sort(edges.begin(), edges.end());

	cout << sol() << '\n';
}
