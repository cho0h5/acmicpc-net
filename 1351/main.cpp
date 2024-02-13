#include <iostream>
#include <vector>

using namespace std;

int n, p, q;
vector<int> vec;

int main() {
	cin >> n >> p >> q;
	
	vec.push_back(1);
	for (int i = 1; i <= n; i++) {
		vec.push_back(vec[i / p] + vec[i / q]);
	}

//	for (int i = 0; i <= n; i++) {
//		cout << vec[i] << ' ';
//	}
//	cout << '\n';

	cout << vec.back() << '\n';
}
