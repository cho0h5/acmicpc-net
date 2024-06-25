#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

long long n;
vector<pair<long long, long long> > v;
vector<long long> maxs;

void print_vector(vector<long long> &v) {
    for (auto it: v) {
        cout << it << ' ';
    }
    cout << '\n';
}

int main() {
    cin >> n;
    v.push_back(make_pair(0, 1));

    for (long long i = 0; i < n; i++) {
        if (i >= 3) {
            long long maxx = maxs[i - 3];
            v.push_back(make_pair(maxx, maxx));
        }
        long long max = 0;
        for (auto &it: v) {
            it.first += it.second;
            if (max < it.first) {
                max = it.first;
            }
        }
        maxs.push_back(max);
    }
    // print_vector(maxs);
    cout << maxs[n-1] << '\n';
}
