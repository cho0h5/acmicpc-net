#include <iostream>
#include <vector>

using namespace std;

long n, m;
vector<long> children[100001];
long s_id[100001];
long e_id[100001];
long next_id = 1;

long state[400004];
long lazy[400004];

void set(long node, long s, long e, long i, long j, long x) {
    if (j < s || e < i) {
        return;
    }

    long mid = (s + e) >> 1;
    long left = node * 2;
    long right = left + 1;

    // Update lazy
    state[node] += lazy[node];
    if (s != e) {
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
    }
    lazy[node] = 0;

    // Enveloped
    if (i <= s && e <= j) {
        lazy[node] += x;
        return;
    }

    // Recursive
    set(left, s, mid, i, j, x);
    set(right, mid + 1, e, i, j, x);
}

long get(long node, long s, long e, long i) {
    long mid = (s + e) >> 1;
    long left = node * 2;
    long right = left + 1;

    // Update lazy
    state[node] += lazy[node];
    if (s != e) {
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
    }
    lazy[node] = 0;

    // Escape
    if (s == e) {
        return state[node];
    }

    // Recursive
    if (i <= mid) {
        return get(left, s, mid, i);
    } else {
        return get(right, mid + 1, e, i);
    }
}

void dfs(const long node) {
    s_id[node] = next_id++;

    for (auto &c: children[node]) {
        dfs(c);
    }

    e_id[node] = next_id - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;

    long parent;
    cin >> parent;
    for (long i = 2; i <= n; i++) {
        cin >> parent;
        children[parent].push_back(i);
    }

    // Re-assign id
    dfs(1);

    for (long i = 0; i < m; i++) {
        long a, b, c;
        cin >> a;
 
        if (a == 1) {
            cin >> b >> c;
            set(1, 1, n, s_id[b], e_id[b], c);
        } else {
            cin >> b;
            cout << get(1, 1, n, s_id[b]) << '\n';
        }
    }

    return 0;
}
