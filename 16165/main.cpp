#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, vector<string>> dict;

int n, m;
string group_name;
string name;
int mem;

int main() {
	cin >> n >> m;
	while (n--) {
		cin >> group_name >> mem;
		while (mem--) {
			cin >> name;
			vector<string> &vec = dict[group_name];
			vec.insert(upper_bound(vec.begin(), vec.end(), name), name);
		}
	}

//	for (auto it = dict.begin(); it != dict.end(); it++) {
//		cout << (*it).first << '\n';
//		for (auto id = it->second.begin(); id != it->second.end(); id++) {
//			cout << *id << ' ';
//		}
//		cout << '\n';
//	}
	while (m--) {
		cin >> name >> n;
		if (n == 1) {
			for (auto it = dict.begin(); it != dict.end(); it++) {
				for (auto id = it->second.begin(); id != it->second.end(); id++) {
					if (*id == name)
						cout << it->first << '\n';
				}
			}

		} else {
			vector<string> &vec = dict[name];
			for (auto it = vec.begin(); it != vec.end(); it++)
				cout << *it << '\n';
		}
	}
}
