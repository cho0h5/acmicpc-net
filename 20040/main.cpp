#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, m;
vector<pair<int, int>> turns;

int parents[500001];

int find(const int x) {
	if (parents[x] == x) return x;
	parents[x] = find(parents[x]);
	return parents[x];
}

void merge(const int a, const int b) {
	int pa = find(a);
	int pb = find(b);
	
	parents[pa] = pb;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		parents[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		if (find(p) == find(q)) {
			cout << i + 1 << '\n';
			return 0;
		}
		merge(p, q);
	}
	cout << 0 << '\n';
}
