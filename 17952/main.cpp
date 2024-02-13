#include <iostream>
#include <stack>
#include <utility>

using namespace std;

stack<pair<int, int>> s;
int t;
int a;
int b;
int c;
int sum;

int main() {
	cin >> t;
	while (t--) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			s.push(make_pair(b, c));
		}

		if (!s.empty()) {
			auto e = s.top();
			s.pop();
			if (e.second == 1)
				sum += e.first;
			else
				s.push(make_pair(e.first, e.second - 1));
		}
	}
	cout << sum << '\n';
}
