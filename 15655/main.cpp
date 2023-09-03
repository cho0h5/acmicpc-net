#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, t;
int ns[8];
vector<int> p;

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> ns[i];
    sort(ns, ns + n);
    for (int i = 0; i < n; i++)
        p.push_back(i >= t);

    do {
        for (int i = 0; i < n; i++)
            if (p[i] == 0)
                cout << ns[i] << ' ';
        cout << '\n';
    } while (next_permutation(p.begin(), p.end()));
}
