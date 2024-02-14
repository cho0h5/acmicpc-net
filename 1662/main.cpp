#include <iostream>
#include <stack>

using namespace std;

string line;
stack<int> ss;

int main() {
	cin >> line;
	for (auto it = line.begin(); it != line.end(); it++) {
		if (ss.empty()) {
			if (*it == '(') {
				ss.push(-1);
			} else if (*it == ')') {
				if (ss.top() == -1) {
					ss.pop();
				} else {
					ss.pop();
					int tmp = ss.top();
				}

			} else {
				if (ss.empty() || ss.top() == -1) {
					ss.push(0);
				} else {
					int tmp = ss.top();
					ss.pop();
					ss.push(tmp + 1);
				}
			}
		}

	}
	
}
