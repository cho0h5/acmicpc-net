#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int n;
        cin >> n;
        if (n < 3) break;

        double a_first, b_first;
        double area = 0;
        cin >> a_first >> b_first;

        double pa = a_first, pb = b_first;
        for (int i = 0; i < n - 1; i++) {
            double ca, cb;
            cin >> ca >> cb;

            area += pa * cb - pb * ca;

            pa = ca;
            pb = cb;
        }

        area += pa * b_first - pb * a_first;
        area /= 2;
        area = -area;


        double v;
        cin >> v;

        printf("BAR LENGTH: %.2f\n", v / area);
    }
}
