#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> tree[400004];
int arr[100001];

void build(int node, int s, int e) {
    if (s == e) {
        tree[node].push_back(arr[s]);
        return;
    }

    int mid = (s + e) >> 1;
    int left = node * 2;
    int right = left + 1;

    build(left, s, mid);
    build(right, mid + 1, e);

    merge(tree[left].begin(), tree[left].end(), tree[right].begin(), tree[right].end(), back_inserter(tree[node]));
}

int get(int node, int s, int e, int i, int j, int x) {
    if (j < s || e < i) {
        return 0;
    }

    if (i <= s && e <= j) {
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), x);
    }

    int mid = (s + e) >> 1;
    int left = node * 2;
    int right = left + 1;
    int sumation = 0;
    sumation += get(left, s, mid, i, j, x);
    sumation += get(right, mid + 1, e, i, j, x);
    return sumation;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << get(1, 1, n, a, b, c) << '\n';
    }
}
