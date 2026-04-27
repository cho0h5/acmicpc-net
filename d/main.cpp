#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int, int>;

int n, m;

int parents[100001];

int get_parent(const int n) {
    if (parents[n] == n) return n;
    return parents[n] = get_parent(parents[n]);
}

bool merge(const int a, const int b) {
    const int pa = get_parent(a);
    const int pb = get_parent(b);

    if (pa == pb) return false;

    parents[pa] = pb;
    return true;
}

vector<iii> edges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    printf("NO\n");

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b, i});
    }

    sort(edges.begin(), edges.end());

    // mst

    vector<int> mst;
    int maximum = 0;
    int sumation = 0;
    for (int i = 0; i < m; i++) {
        auto [c, a, b, index] = edges[i];

        if (merge(a, b)) {
            mst.push_back(index);
            maximum = max(maximum, c);
            sumation += c;
        }
    }

    // for (auto e: mst) {
        // printf("%d\n", e);
    // }

    // mbst

    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }

    int sumation2 = 0;
    vector<int> mbst;
    for (int i = m - 1; i >= 0; i--) {
        auto [c, a, b, index] = edges[i];
        if (c > maximum) continue;

        if (merge(a, b)) {
            mbst.push_back(index);
            sumation2 += c;
        }
    }

    if (sumation == sumation2) {
        printf("NO\n");
    } else {
        printf("YES\n");
        sort(mbst.begin(), mbst.end());
        for (auto e: mbst) {
            printf("%d\n", e);
        }
    }
}
