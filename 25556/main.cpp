#include <deque>
#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

deque<int> dq;
stack<int> ss[4];

int find_stack(int x) {
	int maxx = -1;
	int maxx_i = -1;

	for (int i = 0; i < 4; i++) {
		if (ss[i].empty()) {
			maxx = 0;
			maxx_i = i;
		}
		else if (ss[i].top() <= x) {
			if (maxx < ss[i].top()) {
				maxx = ss[i].top();
				maxx_i = i;
			}
		}
	}
	return maxx_i;
}

int main() {
	fastio();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		dq.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		int ret = find_stack(dq[i]);
		if (ret == -1) {
			cout << "NO\n";
			return 0;
		}
		ss[ret].push(dq[i]);
	}
	cout << "YES\n";
	return 0;
}
