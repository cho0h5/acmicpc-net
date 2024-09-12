#include <iostream>
#include <vector>

using namespace std;

int d, n;
vector<int> ds;
vector<int> ns;

int sol() {
	int id = ds.size() - 1;
	int in = 0;

	while (0 <= id && in < ns.size()) {
//		cout << "id: " << id << '\n';
//		cout << "in: " << in << '\n';
		if (ds[id] >= ns[in]) {
			id -= 1;
			in += 1;
//			cout << "accept\n";
		} else {
			id -= 1;
//			cout << "denied\n";
		}
	}

//		cout << "id: " << id << '\n';
//		cout << "in: " << in << '\n';
	if (in == ns.size() && id >= -1) {
		return id + 2;
	} else {
		return 0;
	}
}

int main() {
	cin >> d >> n;
	int minimum = 2000000001;
	for (int i = 0; i < d; i++) {
		int x;
		cin >> x;
		minimum = min(minimum, x);
		ds.push_back(minimum);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ns.push_back(x);
	}

	cout << sol() << '\n';
}
