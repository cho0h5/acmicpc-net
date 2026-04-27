#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iiii = tuple<long long, long long, long long, long long>;

long long t, n;
vector<iiii> problems;
long long ca, cb, cc;
long long cday;

void sol() {
    for (int i = 0; i < n; i++) {
        auto [p, a, b, c] = problems[i];

        const long long da = max(0LL, a - ca);
        const long long db = max(0LL, b - cb);
        const long long dc = max(0LL, c - cc);

        const long long dtotal = da + db + dc;

        if (cday + dtotal >= p) {
            printf("NO\n");
            return;
        }

        ca += da;
        cb += db;
        cc += dc;

        cday += dtotal + 1;
    }
    printf("YES\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;
        problems.clear();
        ca = 0;
        cb = 0;
        cc = 0;
        cday = 0;

        for (int i = 0; i < n; i++) {
            long long a, b, c, p;
            cin >> a >> b >> c >> p;
            problems.push_back({p, a, b, c});
        }

        sort(problems.begin(), problems.end());
        sol();
    }
}
