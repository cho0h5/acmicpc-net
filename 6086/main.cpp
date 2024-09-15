#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int flow[52][52], capacity[52][52];

int to_index(const char c) {
	if ('A' <= c && c <= 'Z') {
		return c - 'A';
	} else {
		return c - 'a' + 26;
	}
}

const int source = to_index('A');
const int sink = to_index('Z');

int sol() {
	int total_flow = 0;
	while (1) {
		queue<int> q;
		q.push(source);
		vector<int> parents(52, -1);
		parents[source] = source;

		while (q.size() && parents[sink] == -1) {
			const int here = q.front();
			q.pop();

			for (int there = 0; there < 52; there++) {
				// cout << flow[here][there] << " < " << capacity[here][there] << ' ';
				// cout << parents[there] << '\n';
				if (flow[here][there] < capacity[here][there]
						&& parents[there] == -1) {
					parents[there] = here;
					q.push(there);
				}
			}
		}
		if (parents[sink] == -1) {
			break;
		}

		int minimum_flow = 2147483647;
		for (int i = sink; i != source; i = parents[i]) {
			// cout << i << ' ';
			minimum_flow = min(minimum_flow,
					capacity[parents[i]][i] - flow[parents[i]][i]);
		}
		// cout << "0\n";

		for (int i = sink; i != source; i = parents[i]) {
			flow[parents[i]][i] += minimum_flow;
			flow[i][parents[i]] -= minimum_flow;
		}

		total_flow += minimum_flow;
	}
	return total_flow;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b;
		int c;
		cin >> a >> b >> c;
		const int ai = to_index(a);
		const int bi = to_index(b);

		// cout << "init: " << ai << ' ' << bi << '\n';
		// cout << "      " << bi << ' ' << ai << '\n';
		capacity[ai][bi] += c;
		capacity[bi][ai] += c;
	}

	cout << sol() << '\n';
}
