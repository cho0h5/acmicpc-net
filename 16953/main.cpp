#include <iostream>
#include <queue>

using namespace std;

int n, m;
queue<pair<int, int> > q;

int main() {
    cin >> n >> m ;

    q.push({n, 1});

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur.first == m) {
            cout << cur.second << '\n';
            exit(0);
        }
        int c = cur.first * 2;
        int s = cur.second + 1;

        if (c <= 1000000000) q.push({c, s});
        if (c > 100000000) continue;
        c = cur.first * 10 + 1;
        q.push({c, s});
    }
    cout << "-1" << '\n';
}
