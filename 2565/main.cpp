#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<pair<int, int>> lines;
int dp[1000];

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
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    lines.push_back({x, y});
  }
  sort(lines.begin(), lines.end());
  for (auto it = lines.begin(); it != lines.end(); it++) {
    arr.push_back(it->second);
  }

  int maxx = 0;
  int maxi = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = find_max(i);
    if (maxx < dp[i]) {
      maxx = dp[i];
      maxi = i;
    }
  }

  cout << n - maxx << '\n';
  // stack<int> result;
  //  for (int i = maxi; i >= 0; i--) {
  //    if (dp[i] == maxx && (result.empty() || arr[i] < result.top())) {
  //      maxx--;
  //      result.push(arr[i]);
  //    }
  //  }
  //
  //  while (result.size()) {
  //    cout << result.top() << ' ';
  //    result.pop();
  //  }
  //  cout << '\n';
  return 0;
}
