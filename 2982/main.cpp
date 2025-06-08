#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, m;
int a, b, k, g;
vector<int> gs;
vector<pair<int, int>> gs2;
vector<pair<int, int>> graph[1001];
unordered_map<int, int> graph2[1001];

pair<int, int> where_use(int time, int *until) {
    time += 1;

    const pair<int, int> key = {time, 0};
    auto iq = upper_bound(gs2.begin(), gs2.end(), key);

    if (iq == gs2.end()) {
        return {-1, -1};
    }

    *until = iq->first - 1;
    int gn = iq->second;

    if (iq == gs2.begin()) {
        return {-1, -1};
    }

    auto ip = iq;
    ip--;
    int gp = ip->second;

    if (gn > gp) {
        swap(gn, gp);
    }
    return {gn, gp};
}

bool is_used(int cc, int cn, int nn, int *gc) {
    const pair<int, int> key = {cc, 0};
    auto iq = upper_bound(gs2.begin(), gs2.end(), key);
    auto ip = iq;
    ip--;
    if (iq == gs2.end()) {
        return false;
    }

    *gc = iq->first;
    int gn = iq->second;
    int gp = ip->second;

    if (nn == gn && cn == gp) {
        return true;
    } else {
        return false;
    };
}

int dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, a});

    while (q.size()) {
        int cc, cn;
        tie(cc, cn) = q.top();
        q.pop();

        if (cn == b) {
            return cc;
        }

        for (auto &it: graph[cn]) {
            int nn = it.first;
            int nc = cc + it.second;

            int gc;
            if (is_used(cc, cn, nn, &gc)) {
                q.push({nc + (gc - nc), nn});
            } else {
                q.push({nc, nn});
            }
        }
    }

    return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;
    cin >> a >> b >> k >> g;
    for (int i = 0; i < g; i++) {
        int x;
        cin >> x;
        gs.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        graph[p].push_back({q, r});
        graph[q].push_back({p, r});
        graph2[p].insert({q, r});
        graph2[q].insert({p, r});
    }

    // Init gs2
    {
        int time = -k;
        gs2.push_back({time, gs[0]});
        for (int i = 1; i < gs.size(); i++) {
            time += graph2[gs[i - 1]][gs[i]];
            gs2.push_back({time, gs[i]});
        }
    }

    for (int i = -20; i < 30; i++) {
        cout << i << ": ";
        int until;
        auto p = where_use(i, &until);
        cout << p.first << ' ' << p.second << ' ' << until << '\n';
    }

    cout << dijkstra() << '\n';

    return 0;
}
