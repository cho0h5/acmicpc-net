#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void fastio() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<long long, long long> > points;

void input() {
	long long x, y;
	cin >> x >> y;
	points.push_back(make_pair(x, y));
}

long long ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
	long long vx1 = b.first - a.first;
	long long vy1 = b.second - a.second;
	long long vx2 = c.first - b.first;
	long long vy2 = c.second - b.second;
	long long det = (vx1 * vy2) - (vy1 * vx2);
	if (det > 0) return 1;
	if (det < 0) return -1;
	return 0;
}

int is_between_long(long long x, long long y, long long z) {
	if (x <= y) {
		if (x <= z && z <= y) return 1;
		return 0;
	} else {
		if (y <= z && z <= x) return 1;
		return 0;
	}
}

int is_between(int i, int j, int k) {
	if (is_between_long(points[i].first, points[j].first, points[k].first)
		&& is_between_long(points[i].second, points[j].second, points[k].second))
		return 1;
	return 0;
}

int main() {
	fastio();

	input();
	input();
	input();
	input();

	long long c1 = ccw(points[0], points[1], points[2]);
	long long c2 = ccw(points[0], points[1], points[3]);
	long long c3 = ccw(points[2], points[3], points[0]);
	long long c4 = ccw(points[2], points[3], points[1]);

//	cout << "c1: " << c1 << '\n';
//	cout << "c2: " << c2 << '\n';
//	cout << "c3: " << c3 << '\n';
//	cout << "c4: " << c4 << '\n';

	long long offset_x = points[0].first;
	long long offset_y = points[0].second;
	for (int i = 0; i < 4; i++) {
		points[i].first -= offset_x;
		points[i].second -= offset_y;
	}

	if (c1 * c2 == 0 && c3 * c4 == 0) {
		if (is_between(0, 1, 2) || is_between(0, 1, 3)) {
			cout << "1\n";
			return 0;
		}
		if (is_between(2, 3, 0) || is_between(2, 3, 1)) {
			cout << "1\n";
			return 0;
		}
		cout << "0\n";
		return 0;
	}
	else if (c1 * c2 <= 0 && c3 * c4 <= 0) {
		cout << "1\n";
		return 0;
	}

	cout << "0\n";
}
