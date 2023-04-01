#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // init
    queue<int> q;
    int t;
    cin >> t;
    while(t--) {
	string c;
	cin >> c;
	switch(c[1]) {
	    case 'u':
		int x;
		cin >> x;
		q.push(x);
		break;
	    case 'o':
		if(q.empty()) {
		    cout << -1 << '\n';
		} else {
		    cout << q.front() << '\n';
		    q.pop();
		}
		break;
	    case 'i':
		cout << q.size() << '\n';
		break;
	    case 'm':
		cout << q.empty() << '\n';
		break;
	    case 'r':
		cout << (q.empty() ? -1 : q.front()) << '\n';
		break;
	    case 'a':
		cout << (q.empty() ? -1 : q.back()) << '\n';
		break;
	}
    }
}
