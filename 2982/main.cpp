#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
using ii = pair<int, int>;

int n, m;
int a, b, k, g;
vector<int> gs;
vector<pair<int, int>> gs2;
vector<pair<int, int>> graph[1001];
int cost[1001];

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

void dijkstra() {
    fill(cost, cost + 1001, 1e9);
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, a});

    while (q.size()) {
        auto [cc, cn] = q.top(); q.pop();

        for (auto &it: graph[cn]) {
            int nn = it.first;
            int nc = cc + it.second;

            int until;
            auto where = where_use(cc, &until);

            int tmp = 0;
            if ((where.first == cn && where.second == nn) || (where.first == nn && where.second == cn)) {
                tmp = until - cc + 1;
            }

            if (cost[nn] <= nc + tmp) continue;

            cost[nn] = nc + tmp;
            q.push({nc + tmp, nn});
        }
    }
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
    }

    // Init gs2
    {
        int time = -k;
        gs2.push_back({time, gs[0]});
        for (int i = 1; i < gs.size(); i++) {
            sort(graph[gs[i - 1]].begin(), graph[gs[i - 1]].end());
            pair<int, int> key = {gs[i], 0};
            const auto &it = lower_bound(graph[gs[i - 1]].begin(), graph[gs[i - 1]].end(), key);

            time += it->second;
            gs2.push_back({time, gs[i]});
        }
    }

    dijkstra();
    cout << cost[b] << '\n';

    return 0;
}
