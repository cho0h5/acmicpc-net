#include <iostream>
#include <stack>

using namespace std;

int n;
int ns[1000000];
int answer[1000000];
int m[1000001];
stack<pair<int, int>> s;

void sol() {
	for (int i = n - 1; i >= 0; i--) {
		const int Ai = ns[i];

		while (s.size() && s.top().second <= m[Ai]) {
			s.pop();
		}

		if (s.empty()) {
			answer[i] = -1;
		} else {
			answer[i] = s.top().first;
		}
		s.push({Ai, m[Ai]});
	}
}

void print_answer() {
	for (int i = 0; i < n; i++) {
		cout << answer[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ns[i];
		m[ns[i]] += 1;
	}

	sol();
	print_answer();
}
