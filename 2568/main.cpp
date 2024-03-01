#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int> dp;
vector<int> dp2;

void backtrack(int target, int i) {
  if (i < 0)
    return;
  if (target == dp2[i]) {
    backtrack(target - 1, i - 1);
  } else {
    backtrack(target, i - 1);
    cout << arr[i].first << '\n';
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    arr.push_back({x, y});
  }
  sort(arr.begin(), arr.end());
  dp2.reserve(arr.size());

  for (auto it = arr.begin(); it != arr.end(); it++) {
    if (dp.empty() || dp.back() < it->second) {
      dp2.push_back(dp.size());
      dp.push_back(it->second);
    } else {
      auto ip = lower_bound(dp.begin(), dp.end(), it->second);
      dp2.push_back(distance(dp.begin(), ip));
      *ip = it->second;
    }
  }

  cout << n - dp.size() << '\n';
  backtrack(dp.size() - 1, dp2.size() - 1);
  return 0;
}
