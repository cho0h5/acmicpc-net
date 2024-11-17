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
    pq.emplace(-1, 1);

    while (pq.size()) {
        auto [curr_cost, curr_index] = pq.top();
        curr_cost = -curr_cost;
        const int next_cost = curr_cost + 1;
        pq.pop();
        // cout << "pop: " << curr_index << " - " << curr_cost << '\n';

        if (curr_index == n) {
            return curr_cost;
        }

        for (auto &h: hs) {
            if (h.find(curr_index) == h.end()) {
                continue;
            }

            for (auto &next_index: h) {
                if (vst.find(next_index) == vst.end()) {
                    vst.insert(next_index);
//                    cout << "push: " << curr_index << " - " << curr_cost << ", "
//                        << next_index << " - " << next_cost << '\n';
                    pq.emplace(-next_cost, next_index);
                }
            }
            h.clear();
        }
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
