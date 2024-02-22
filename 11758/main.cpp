#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

	double det = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
	if (det > 0) cout << "1\n";
	else if (det < 0) cout << "-1\n";
	else cout << "0\n";
}
