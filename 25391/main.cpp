#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({y, x});
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());

    long long sumation = 0;
    for (int i = 0; i < k; i++) {
        sumation += v[i].second;
    }
    vector<int> vv;
    for (int i = k; i < n; i++) {
        vv.push_back(v[i].second);
    }
    sort(vv.begin(), vv.end(), greater<int>());
    for (int i = 0; i < m; i++) {
        sumation += vv[i];
    }
    printf("%lld\n", sumation);
}
