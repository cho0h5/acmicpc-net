#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;

void solution() {
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int> > minq;
    unordered_map<int, int> m;
    int size = 0;

    int t;
    cin >> t;
    while(t--) {
	char c;
	cin >> c;
	if(c == 'I') {
	    int n;
	    cin >> n;
	    maxq.push(n);
	    minq.push(n);
	    size++;
	    m[n]++;
	} else {
	    int n;
	    cin >> n;
	    if(size == 0) continue;

	    if(n == -1) {
		while(m[minq.top()] == 0) minq.pop();
		m[minq.top()]--;
		minq.pop();
		size--;
	    } else {
		while(m[maxq.top()] == 0) maxq.pop();
		m[maxq.top()]--;
		maxq.pop();
		size--;
	    }
	}
    }
    
    if(size == 0) {
	cout << "EMPTY\n";
    } else if(size == 1) {
	while(m[minq.top()] == 0) minq.pop();
	cout << minq.top() << ' ' << minq.top() << '\n';
    } else {
	while(m[minq.top()] == 0) minq.pop();
	while(m[maxq.top()] == 0) maxq.pop();
	cout << maxq.top() << ' ' << minq.top() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solution();
}
