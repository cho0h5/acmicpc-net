#include <iostream>
#include <vector>
#include <tuple>

#define INF 99999999

using namespace std;

long long n, m;
vector<tuple<long long, long long, long long>> graph;
long long costs[501];

void bellman() {
	for (long long i = 0; i < n - 1; i++) {
		for (auto edge: graph) {
			long long a, b, c;
			tie(a, b, c) = edge;

			if (costs[a] == INF) continue;
			if (costs[b] > costs[a] + c) {
				costs[b] = costs[a] + c;
			}
		}
	}

	for (auto edge: graph) {
		long long a, b, c;
		tie(a, b, c) = edge;

		if (costs[a] == INF) continue;
		if (costs[b] > costs[a] + c) {
			cout << "-1\n";
			exit(0);
		}
	}
}

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	fastio();
	for (long long i = 0; i < 501; i++) {
		costs[i] = INF;
	}
	cin >> n >> m;
	for (long long i = 0; i < m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		graph.push_back({a, b, c});
	}

	costs[1] = 0;
	bellman();

	for (long long i = 2; i <= n; i++) {
		if (costs[i] == INF)
			cout << "-1\n";
		else
			cout << costs[i] << '\n';
	}
}
