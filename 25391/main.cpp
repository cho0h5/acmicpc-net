#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ii {
    int first;
    int second;
};

int n, m, k;
ii v[200000];

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
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v, v + n, compare1);
    sort(v + k, v + n, compare2);

    long long sumation = 0;
    for (int i = 0; i < k + m; i++) {
        sumation += v[i].second;
    }
    printf("%lld\n", sumation);
}
