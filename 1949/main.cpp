#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ii = pair<int, int>;

int n;
int populate[10000];
vector<vector<int>> graph;
vector<vector<int>> tree;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> populate[i];
    }
    graph.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

void make_tree() {
    queue<int> q;
    vector<int> vst(n + 1, 0);
    q.push(1);
    tree.assign(n + 1, vector<int>());
    while (q.size()) {
        const int curr = q.front();
        q.pop();
        vst[curr] = 1;

        for (int i = 0; i < graph[curr].size(); i++) {
            const int next = graph[curr][i];
            if (vst[next] == 1) {
                continue;
            }

            tree[curr].push_back(next);
            q.push(next);
        }
    }
}

ii search(const int curr) {
    if (tree[curr].size() == 0) {
        return {populate[curr - 1], 0};
    } else {
        int with_curr = populate[curr - 1];
        int without_curr = 0;
        for (int i = 0; i < tree[curr].size(); i++) {
            ii result = search(tree[curr][i]);
            with_curr += result.second;
            without_curr += max(result.first, result.second);
        }
        return {with_curr, without_curr};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    make_tree();

    ii result = search(1);
    if (result.first > result.second) {
        cout << result.first << '\n';
    } else {
        cout << result.second << '\n';
    }
}
