#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> ns;

void print_ns() {
  cout << "status: ";
  for (auto it = ns.begin(); it != ns.end(); ++it) {
    cout << *it << ' ';
  }
  cout << '\n';
}

void prune_ns() {
  for (auto it = ns.begin(); it != ns.end();) {
    if (*it <= 0) {
      cout << "debug " << *it << '\n';
      it = ns.erase(it);
    } else {
      ++it;
    }
  }
}

int sol() {
  int count = 0;

  while (1) {
    print_ns();
    prune_ns();
    if (ns.empty())
      return count;

    sort(ns.begin(), ns.end(), greater<>());

    ns[0] -= 9;
    if (ns.size() >= 2)
      ns[1] -= 3;
    if (ns.size() >= 3)
      ns[1] -= 1;
    count += 1;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ns.push_back(x);
  }

  cout << sol() << '\n';
}
