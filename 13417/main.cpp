#include <deque>
#include <iostream>

using namespace std;

int t;
int n;
char c;
deque<char> dq;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		while (n--) {
			cin >> c;
			if (dq.empty())
				dq.push_back(c);
			else if (dq.front() >= c)
				dq.push_front(c);
			else
				dq.push_back(c);
		}
		for (auto it = dq.begin(); it != dq.end(); it++)
			cout << *it;
		cout << '\n';
		dq.clear();
	}
}
