#include <iostream>
#include <queue>

using namespace std;

int sol(const vector<int> &costs, const vector<vector<int>> &graph,
        vector<int> &degree, const int target) {
  const int n = costs.size() - 1;

  queue<int> q;
  for (int i = 1; i < degree.size(); i++) {
    if (degree[i] == 0) {
      q.push(i);
    }
  }

  vector<int> result;
  vector<int> start_time(n + 1);

  for (int i = 0; i < n; i++) {
    if (q.empty())
      return -1;

    const int n = q.front();
    q.pop();

    result.push_back(n);

    for (int j = 0; j < graph[n].size(); j++) {
      int m = graph[n][j];
      start_time[m] = max(start_time[m], start_time[n] + costs[n]);
      degree[m] -= 1;
      if (degree[m] == 0) {
        if (m == target) {
          return start_time[m] + costs[m];
        }
        q.push(m);
      }
    }
  }
  return start_time[target] + costs[target];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> costs;
    costs.push_back(-1);
    vector<vector<int>> graph(n + 1);
    vector<int> degree(n + 1);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      costs.push_back(x);
    }
    for (int i = 0; i < k; i++) {
      int p, q;
      cin >> p >> q;
      graph[p].push_back(q);
      degree[q] += 1;
    }
    int target;
    cin >> target;

    cout << sol(costs, graph, degree, target) << '\n';
  }
}
