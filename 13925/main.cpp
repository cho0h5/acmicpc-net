#include <iostream>

using namespace std;

int n, m;
int state[400004];
int lazy_add[400004];
int lazy_mul[400004];
int lazy_ovr[400004];

void update_add(int node, int s, int e, int i, int j, int x) {
}

void update_mul(int node, int s, int e, int i, int j, int x) {
}

void update_ovr(int node, int s, int e, int i, int j, int x) {
}

int retreive(int node, int s, int e, int i, int j) {
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> state[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update_add(1, 1, n, b, c, d);
        } else if (a == 2) {
            cin >> b >> c >> d;
            update_mul(1, 1, n, b, c, d);
        } else if (a == 3) {
            cin >> b >> c >> d;
            update_ovr(1, 1, n, b, c, d);
        } else {
            cin >> b >> c;
            cout << retreive(1, 1, n, b, c) << '\n';
        }
    }

    return 0;
}
