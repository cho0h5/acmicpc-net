#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>

#define EPSILON 0.000001

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

long long px1, py1;
long long px2, py2;
long long px3, py3;
long long px4, py4;
double r1;
double r2;

void input() {
	cin >> px1 >> py1;
	cin >> px2 >> py2;
	cin >> px3 >> py3;
	cin >> px4 >> py4;
	r1 = (double)(py2 - py1) / (px2 - px1);
	r2 = (double)(py4 - py3) / (px4 - px3);
}

double cross_x() {
	return (r1 * px1 - r2 * px3 - py1 + py3) / (r1 - r2);
}

int main() {
	fastio();

	input();

	if (abs(r2 - r1) < EPSILON) {
		cout << "0\n";
		return 0;
	}

	long long cross_point = cross_x();

	if (!(px1 <= cross_point && cross_point <= px2)) {
		cout << "0\n";
		return 0;
	}
	if (!(px3 <= cross_point && cross_point <= px4)) {
		cout << "0\n";
		return 0;
	}
	cout << "1\n";
}
