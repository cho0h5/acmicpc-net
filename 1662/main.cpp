#include <cctype>
#include <iostream>
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

int recursion(string line, int *i) {
	// cout << "debug: " << line << ' ' << *i << '\n';
	int len = 0;

	while (1) {
		if (*i >= line.size() || line[*i] == ')') {
			*i += 1;
			// cout << "debug: " << len << '\n';
			return len;
		} else if (*i + 1 < line.size() && line[*i + 1] == '(') {
			int mul = line[*i];
			*i += 2;
			len += (mul - '0') * recursion(line, i);
		} else if (isdigit(line[*i])) {
			len += 1;
			*i += 1;
		} else {
			exit(1);
		}
	}
}

int main() {
	fastio();

	string line;
	cin >> line;
	int i = 0;
	cout << recursion(line, &i) << '\n';
}
