#include <iostream>

using namespace std;

long long n;
long long q;

long long tree[4000000];
long long lazy[4000000];

void update(int node, int s, int e) {
    if (s == e) {
        tree[node] += lazy[node];
        lazy[node] = 0;
    } else {
        const int left = node * 2;
        const int right = left + 1;

        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
        lazy[node] = 0;
    }
}

void add(int node, int s, int e, int i, int j, long long x) {
    if (j < s || e < i) {
        return;
    }

    update(node, s, e);

    if (s == e) {
        tree[node] += x;
        return;
    }

    if (i <= s && e <= j) {
        lazy[node] += x;
        return;
    }

    const int left = node * 2;
    const int right = left + 1;
    const int mid = (s + e) / 2;
    add(left, s, mid, i, j, x);
    add(right, mid + 1, e, i, j, x);
}

long long get(int node, int s, int e, int i) {
    if (i == 0) {
        return 0;
    }

    update(node, s, e);

    if (s == e) {
        return tree[node];
    }

    const int left = node * 2;
    const int right = left + 1;
    const int mid = (s + e) / 2;

    if (i <= mid) {
        return get(left, s, mid, i);
    } else {
        return get(right, mid + 1, e, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        if (a == 1) {
            add(1, 1, n, b, n, c);
        } else {
            const long long s_price = get(1, 1, n, b - 1);
            const long long e_price = get(1, 1, n, c);

            // cout << s_price << ' ' << e_price << '\n';
            cout << (e_price - s_price) << '\n';
        }
    }

    return 0;
}
