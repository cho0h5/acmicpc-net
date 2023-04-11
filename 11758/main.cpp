#include <iostream>
#define E 0.000001

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    double dx1 = x2 - x1;
    double dy1 = y2 - y1;
    double dx2 = x3 - x2;
    double dy2 = y3 - y2;

    double a = dy1 / dx1;
    double b = dy2 / dx2;

    if((b - a < E && b - a > -E) || ((dx1 < E && dx1 > -E) && (dx2 < E && dx2 > -E)))
	cout << 0;
    else if((dx1 * dx2 > 0 && a < b) || (dx1 * dx2 < 0 && a > b))
	cout << 1;
    else if((dx1 * dx2 > 0 && a > b) || (dx1 * dx2 < 0 && a < b))
	cout << -1;
}
