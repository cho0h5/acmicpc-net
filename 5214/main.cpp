#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int n, k, m;
vector<unordered_set<int>> hs;

int sol() {
    unordered_set<int> vst;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < hs.size(); i++) {
        if (hs[i].find(1) != hs[i].end()) {
            pq.emplace(-2, i);
        }
    }

    while (pq.size()) {
        auto [curr_cost, curr_hiper] = pq.top();
        const int next_cost = curr_cost - 1;
        pq.pop();

        if (hs[curr_hiper].find(n) != hs[curr_hiper].end()) {
            return -curr_cost;
        }

        for (int i = 0; i < hs.size(); i++) {
            if (hs[i].empty()) continue;
            if (vst.find(i) == vst.end()) {
                for (auto &next_index: hs[curr_hiper]) {
                    if (hs[i].find(next_index) != hs[i].end()) {
                        vst.insert(i);
                        pq.push({next_cost, i});
                    }
                }
            }
        }
        hs[curr_hiper].clear();
    }

    return -1;
}

void input() {
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        unordered_set<int> h;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            h.insert(x);
        }
        hs.push_back(h);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cout << sol() << '\n';
}
