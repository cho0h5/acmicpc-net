#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int n, k, m;
vector<unordered_set<int>> hs;
vector<unordered_set<int>> is;

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

        for (auto &next_index: hs[curr_hiper]) {
            for (auto &next_hiper: is[next_index]) {
                if (hs[next_hiper].empty()) continue;
                if (vst.find(next_hiper) == vst.end()) {
                    vst.insert(next_hiper);
                    pq.push({next_cost, next_hiper});
                }
            }
        }
        hs[curr_hiper].clear();
    }

    return -1;
}

void input() {
    cin >> n >> k >> m;
    is.assign(n + 1, unordered_set<int>());
    for (int i = 0; i < m; i++) {
        unordered_set<int> h;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            h.insert(x);
            is[x].insert(i);
        }
        hs.push_back(h);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    cout << sol() << '\n';
}
