#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<pair<int, int> > g[10001];
int p[10001];
queue<int> q;

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    int mmax = 1;
    int maxi = 1;
    q.push(1);
    p[1] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 0; i < g[cur].size(); i++) {
            int nx = g[cur][i].first;

            if (p[nx] != 0) continue;

            q.push(nx);
            p[nx] = p[cur] + g[cur][i].second;
            if (p[nx] > mmax) {
                mmax = p[nx];
                maxi = nx;
            }
        }
    }
    for (int i = 0; i <= n; i++) p[i] = 0;

    q.push(maxi);
    p[maxi] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 0; i < g[cur].size(); i++) {
            int nx = g[cur][i].first;

            if (p[nx] != 0) continue;

            q.push(nx);
            p[nx] = p[cur] + g[cur][i].second;
            if (p[nx] > mmax) {
                mmax = p[nx];
                maxi = nx;
            }
        }
    }
    cout << mmax - 1 << '\n';
}
