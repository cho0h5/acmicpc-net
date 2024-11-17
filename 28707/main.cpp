#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n, m;
vector<int> as;
vector<vector<int>> ms;

int sol() {
    set<vector<int>> vst;
    priority_queue<pair<int, vector<int>>> pq;
    pq.push({0, as});

    while (pq.size()) {
        auto [curr_cost, curr_as] = pq.top();
        curr_cost = -curr_cost;
        pq.pop();

        if (is_sorted(curr_as.begin(), curr_as.end())) {
            return curr_cost;
        }

        if (vst.find(curr_as) == vst.end()) {
            vst.insert(curr_as);
        } else {
            continue;
        }

        for (int i = 0; i < m; i++) {
            auto next_as = curr_as;
            int next_cost = curr_cost + ms[i][2];
            swap(next_as[ms[i][0] - 1], next_as[ms[i][1] - 1]);
            pq.push({-next_cost, next_as});
        }
    }

    return -1;
}

void input() {
    cin >> n;
    as.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }
    cin >> m;
    ms.assign(m, vector(3, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> ms[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    cout << sol() << '\n';
}
