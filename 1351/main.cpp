#include <iostream>
#include <map>

using namespace std;

long long n, p, q;
map<long long, long long> m;

long long recursive(long long n) {
	if (n == 0)
		return 1;
	if (m.find(n) != m.end())
		return m[n];
	long long value = recursive(n / p) + recursive(n / q);
	m[n] = value;
	return value;
}

int main() {
	cin >> n >> p >> q;
	
	cout << recursive(n) << '\n';
}
