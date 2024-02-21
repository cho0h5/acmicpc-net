#include <cstring>
#include <iostream>
#include <string>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int contain(string a, string nohave) {
	for (auto it = a.begin(); it != a.end(); it++) {
		if (strchr(nohave.c_str(), *it) != NULL)
			return 1;
	}
	return 0;
}

int main() {
	fastio();
	int target;
	int n;
	string nohave;
	cin >> target >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		nohave.push_back(c);
	}

	int i, j;
	for (i = target; i >= 0; i--) {
		if (!contain(to_string(i), nohave))
			break;
	}
	if (i == -1) i = -10000000;
	for (j = target; j < 1100000; j++) {
		if (!contain(to_string(j), nohave))
			break;
	}

	int x = abs(100 - target);
	int y = abs(i - target) + to_string(i).size();
	int z = abs(j - target) + to_string(j).size();
//	cout << i << '\n';
//	cout << j << '\n';
//	cout << x << ' ' << y << ' ' << z << '\n';
	cout << min(x, min(y, z)) << '\n';
}
