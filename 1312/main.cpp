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

int a, b, n;

int main() {
	fastio();

	cin >> a >> b >> n;

	for (int i = 0; i < n; i++) {
		int tmp = a / b;
		a -= b * tmp;
		// cout << a << '\n';
		a *= 10;
	}
	cout << (int)(a / b) << '\n';
}
