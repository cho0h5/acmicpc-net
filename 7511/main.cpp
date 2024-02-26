#include <iostream>

using namespace std;

void fastio() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
}

int parent[1000001];

int get_parent(int child) {
  if (child == parent[child])
    return child;
  parent[child] = get_parent(parent[child]);
  return parent[child];
}

int main() {
  fastio();
  int t;
  cin >> t;
  for (int h = 0; h < t; h++) {
    cout << "Scenario " << h + 1 << ":\n";
    int n, k, m;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
      parent[i] = i;
    while (k--) {
      int x, y;
      cin >> x >> y;
      int px = get_parent(x);
      int py = get_parent(y);
      if (px < py)
        parent[y] = px;
      else
        parent[x] = py;
    }
    cin >> m;
    while (m--) {
      int x, y;
      cin >> x >> y;
      int px = get_parent(x);
      int py = get_parent(y);
      if (px == py)
        cout << "1\n";
      else
        cout << "0\n";
    }
    //    for (int d = 0; d < n; d++) {
    //      cout << parent[d] << ' ';
    //    }
    cout << '\n';
  }
}
