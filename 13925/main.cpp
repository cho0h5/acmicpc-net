#include <iostream>

using namespace std;

int n, m;
int state[400004];
int lazy_add[400004];
int lazy_mul[400004];
int lazy_ovr[400004];

void propagate_add(int node, int s, int e);
void propagate_mul(int node, int s, int e);
void propagate_ovr(int node, int s, int e);

void propagate_add(int node, int s, int e) {
    int mid = (s + e) >> 1;
    int left = node >> 1;
    int right = left + 1;

    if (lazy_add[node] == 0) {
        return;
    }

    propagate_mul(left, s, mid);
    propagate_ovr(left, s, mid);
    propagate_mul(right, mid + 1, e);
    propagate_ovr(right, mid + 1, e);

    if (s != e) {
        lazy_add[left] = lazy_add[node];
        lazy_add[right] = lazy_add[node];
    }

    state[node] += lazy_add[node];
    lazy_add[node] = 0;

    return;
}

void propagate_mul(int node, int s, int e) {
    int mid = (s + e) >> 1;
    int left = node >> 1;
    int right = left + 1;

    if (lazy_mul[node] == 0) {
        return;
    }

    propagate_add(left, s, mid);
    propagate_ovr(left, s, mid);
    propagate_add(right, mid + 1, e);
    propagate_ovr(right, mid + 1, e);

    if (s != e) {
        lazy_mul[left] = lazy_mul[node];
        lazy_mul[right] = lazy_mul[node];
    }

    state[node] *= lazy_mul[node];
    lazy_mul[node] = 0;

    return;
}

void propagate_ovr(int node, int s, int e) {
    int mid = (s + e) >> 1;
    int left = node >> 1;
    int right = left + 1;

    if (lazy_ovr[node] == 0) {
        return;
    }

    propagate_add(left, s, mid);
    propagate_mul(left, s, mid);
    propagate_add(right, mid + 1, e);
    propagate_mul(right, mid + 1, e);

    if (s != e) {
        lazy_ovr[left] = lazy_ovr[node];
        lazy_ovr[right] = lazy_ovr[node];
    }

    state[node] = lazy_ovr[node];
    lazy_ovr[node] = 0;

    return;
}

void update_add(int node, int s, int e, int i, int j, int x) {
    if (j < s || e < i) {
        return;
    }

    propagate_add(node, s, e);
    propagate_mul(node, s, e);
    propagate_ovr(node, s, e);

    if (i <= s && e <= j) {
        lazy_add[node] = x;
        return;
    }

    state[node] += x;

    int mid = (s + e) >> 1;
    update_add(node * 2, s, mid, i, j, x);
    update_add(node * 2 + 1, mid + 1, e, i, j, x);
}

void update_mul(int node, int s, int e, int i, int j, int x) {
    if (j < s || e < i) {
        return;
    }

    propagate_add(node, s, e);
    propagate_mul(node, s, e);
    propagate_ovr(node, s, e);

    if (i <= s && e <= j) {
        lazy_mul[node] = x;
        return;
    }

    state[node] *= x;

    int mid = (s + e) >> 1;
    update_mul(node * 2, s, mid, i, j, x);
    update_mul(node * 2 + 1, mid + 1, e, i, j, x);
}

void update_ovr(int node, int s, int e, int i, int j, int x) {
}

int retreive(int node, int s, int e, int i, int j) {
    if (j < s || e < i) {
        return 0;
    }

    propagate_add(node, s, e);
    propagate_mul(node, s, e);
    propagate_ovr(node, s, e);

    if (i <= s && e <= j) {
        return state[node];
    }

    int mid = (s + e) >> 1;
    return retreive(node * 2, s, mid, i, j) + retreive(node * 2 + 1, mid + 1, e, i, j);
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update_add(1, 1, n, i, i, x);
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
