#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> s;
int x;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> x;
		switch (x) {
			case 1:
				cin >> x;
				s.push(x);
				break;
			case 2:
				if (s.empty())
					cout << "-1\n";
				else {
					cout << s.top() << '\n';
					s.pop();
				}
				break;
			case 3:
				cout << s.size() << '\n';
				break;
			case 4:
				cout << s.empty() << '\n';
				break;
			case 5:
				if (s.empty())
					cout << "-1\n";
				else
					cout << s.top() << '\n';
				break;
		}
	}
	
}
