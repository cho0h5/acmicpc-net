#include <iostream>
#include <queue>
#include <map>

using namespace std;

int n;
int ns[1000000];
int answer[1000000];
priority_queue<pair<int, int>> pq;
map<int, int> m;

void sol() {
	for (int i = n - 1; i >= 0; i--) {
		if (pq.empty()) {
			answer[i] = -1;
		} else {
			answer[i] = pq.top().second;
		}
		pq.push({m[ns[n - 1]], ns[n - 1]});
	}
}

void print_answer() {
	for (int i = 0; i < n; i++) {
		cout << answer[i] << ' ';
	}
	cout << '\n';
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ns[i];
		m[ns[i]] += 1;
	}

	sol();
	print_answer();
}
