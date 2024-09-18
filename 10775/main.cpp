#include <iostream>

using namespace std;

int g, p;

int parents[100001];

int find(const int node) {
	if (parents[node] == node) return node;
	parents[node] = find(parents[node]);
	return parents[node];
}

void merge(const int a, const int b) {
	const int pa = find(a);
	const int pb = find(b);

	if (pa < pb) {
		parents[pb] = pa;
	} else {
		parents[pa] = pb;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> g >> p;

	for (int i = 0; i <= g; i++) {
		parents[i] = i;
	}
	int count = 0;
	for (int i = 0; i < p; i++) {
		int x;
		cin >> x;

		const int px = find(x) - 1;
		if (px == -1) {
			break;
		} else {
			merge(px, x);
			count += 1;
		}
	}
	cout << count << '\n';
}
