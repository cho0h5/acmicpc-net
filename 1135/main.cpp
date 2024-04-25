#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

void fastio() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int n;
map<int, vector<int>> tree;

void print_tree() {
  for (auto &t : tree) {
    cout << t.first << " : ";
    for (auto &v : t.second) {
      cout << v << " ";
    }
    cout << "\n";
  }
}

int traverse(int node) {
  if (tree[node].size() == 0) {
    return 0;
  }
  vector<int> costs;
  for (int child : tree[node]) {
    costs.push_back(traverse(child));
  }
  sort(costs.begin(), costs.end(), greater<int>());

  int max_cost = 0;
  // cout << "node: " << node << "\n";
  // cout << "costs :";
  for (int i = 0; i < costs.size(); i++) {
    int temp = costs[i] + i + 1;
    // cout << temp << " ";
    max_cost = max(max_cost, temp);
  }
  // cout << "\n";
  return max_cost;
}

int main() {
  fastio();
  cin >> n;
  for (int i = 0; i < n; i++) {
    int parent;
    cin >> parent;
    tree[parent].push_back(i);
  }

  // print_tree();
  cout << traverse(0) << "\n";
}
