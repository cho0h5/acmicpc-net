#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<int> dp;

void fastio() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int find_max(int index) {
  int maxx = 0;
  for (int i = 0; i < index; i++) {
    if (arr[i] < arr[index]) {
      maxx = max(maxx, dp[i]);
    }
  }
  return maxx + 1;
}

int main() {
  fastio();
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }

  for (auto it = arr.begin(); it != arr.end(); it++) {
    if (dp.empty()) {
      dp.push_back(*it);
    } else if (dp.back() >= *it) {
      auto ip = lower_bound(dp.begin(), dp.end(), *it);
      *ip = *it;
    } else {
      dp.push_back(*it);
    }
  }

  cout << dp.size() << '\n';
  return 0;
}
