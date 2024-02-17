#include <cstring>
#include <iostream>
#include <string>
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

int contain(string a, string b) {
	for (int i = 0; i < a.size(); i++) {
		if (strchr(b.c_str(), a[i]) != NULL)
			return 1;
	}
	return 0;
}

int main() {
	fastio();
	int target;
	string nohave;
	cin >> target;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char num;
		cin >> num;
		nohave.push_back(num);
	}

	int i;
	for (i = target; i >= 0; i--) {
		string can = to_string(i);
		if (!contain(can, nohave))
			break;
	}
	int j;
	for (j = target; j <= 1000000; j++) {
		string can = to_string(j);
		if (!contain(can, nohave))
			break;
	}
	// cout << i << '\n';
	// cout << j << '\n';
	int l = to_string(target).size();
	int minn = min(abs(100 - target), min(abs(i - target) + l, abs(j - target) + l));
	cout << minn << '\n';
}
