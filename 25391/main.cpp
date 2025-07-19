#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;

int n, m, k;

bool compare1(const ii &a, const ii &b) {
    return a.first > b.first;
}

bool compare2(const ii &a, const ii &b) {
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    vector<ii> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({y, x});
    }
    sort(v.begin(), v.end(), compare1);
    sort(v.begin() + k, v.end(), compare2);

    long long sumation = 0;
    for (int i = 0; i < k + m; i++) {
        sumation += v[i].second;
    }
    printf("%lld\n", sumation);
}
