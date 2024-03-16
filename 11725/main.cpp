#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int parent[100001];
int vst[100001];
map<int, vector<int>> graph;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	queue<int> q;
	vst[1] = 1;
	q.push(1);
	while (q.size()) {
		int n = q.front(); q.pop();

		auto vec = graph[n];
		for (auto it = vec.begin(); it != vec.end(); it++) {
			if (vst[*it]) continue;
			vst[*it] = 1;
			q.push(*it);
			parent[*it] = n;
		}
	}

	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
}
