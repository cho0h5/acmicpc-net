#include <iostream>
#include <tuple>
#include <vector>
#include <set>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

set<tuple<int, int, int>> vst;

void print_bottles(const vector<int> &bottles, const int capacity[3]) {
	for (int i = 0; i < 3; i++) {
		cout << "[" << bottles[i] << "/" << capacity[i] << "] ";
	}
	cout << '\n';
}

int pour(vector<int> &bottles, const int capacity[3], int from, int to) {
	const int carry = min(capacity[to] - bottles[to], bottles[from]);

//	print_bottles(bottles, capacity);
//	cout << "carry: " << carry << '\n';

	if (carry == 0) return 0;
	bottles[from] -= carry;
	bottles[to] += carry;
	return 1;
}

void dfs(set<int> &cases, vector<int> &bottles, const int capacity[3]) {
	if (vst.find(make_tuple(bottles[0], bottles[1], bottles[2])) != vst.end())
		return ;
	if (bottles[0] == 0)
		cases.insert(bottles[2]);
	vst.insert(make_tuple(bottles[0], bottles[1], bottles[2]));

	vector<int> bottles1 = bottles;
	if (pour(bottles1, capacity, 0, 1))
		dfs(cases, bottles1, capacity);

	vector<int> bottles2 = bottles;
	if (pour(bottles2, capacity, 0, 2))
		dfs(cases, bottles2, capacity);

	vector<int> bottles3 = bottles;
	if (pour(bottles3, capacity, 1, 0))
		dfs(cases, bottles3, capacity);

	vector<int> bottles4 = bottles;
	if (pour(bottles4, capacity, 1, 2))
		dfs(cases, bottles4, capacity);

	vector<int> bottles5 = bottles;
	if (pour(bottles5, capacity, 2, 0))
		dfs(cases, bottles5, capacity);

	vector<int> bottles6 = bottles;
	if (pour(bottles6, capacity, 2, 1))
		dfs(cases, bottles6, capacity);

}

int main() {
	fastio();

	int capacity[3];
	vector<int> bottles;
	cin >> capacity[0];
	cin >> capacity[1];
	cin >> capacity[2];
	bottles.push_back(0);
	bottles.push_back(0);
	bottles.push_back(capacity[2]);


	// print_bottles(bottles, capacity);
	set<int> cases;
	dfs(cases, bottles, capacity);

	for (auto it = cases.begin(); it != cases.end(); it++) {
		cout << *it << ' ';
	}
	cout << '\n';
}
