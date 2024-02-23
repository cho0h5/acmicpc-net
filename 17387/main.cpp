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
	if (c1 * c2 < 0 && c3 * c4 < 0)
		cout << "1\n";
	else
		cout << "0\n";

}
