#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
using ii=pair<int, int>;

int n, c;

vector<ii> nodes;
vector<ii> graph[2000];
bool is_merged[2000];
int total_merged;
int total_cost;

void prim() {
    priority_queue<ii, vector<ii>, greater<ii>> q;

    is_merged[0] = true;
    total_merged += 1;
    for (auto &edge: graph[0]) {
        q.push(edge);
    }

    while (q.size()) {
        auto [c, n] = q.top();
        q.pop();

        if (is_merged[n]) continue;

        // printf("Merged: %d (cost: %d)\n", n, c);

        is_merged[n] = true;
        total_merged += 1;
        total_cost += c;

        for (auto &edge: graph[n]) {
            if (is_merged[edge.second]) continue;

            q.push(edge);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        nodes.push_back({a, b});
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            const int dx = nodes[j].first - nodes[i].first;
            const int dy = nodes[j].second - nodes[i].second;
            const int cost = dx * dx + dy * dy;

            if (cost < c) continue;

            // printf("Add edge: %d <-> %d (%d)\n", i, j, cost);

            graph[i].push_back({cost, j});
            graph[j].push_back({cost, i});
        }
    }

    prim();

    // for (int i = 0; i < n; i++) {
        // printf("%d ", is_merged[i]);
    // }
    // printf("\n");

    printf("%d\n", total_merged == n ? total_cost : -1);

    return 0;
}
