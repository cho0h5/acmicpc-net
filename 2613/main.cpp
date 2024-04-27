#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[300];

vector<int> candidate;
vector<int> viable;
int minn = 99999999;

int subprogram(int target) {
  int max_sum = 0;
  int count = 0;

  // cout << "member: ";
  int sum = 0;
  int e_count = 0;
  for (int i = 0; i < n; i++) {
    if (m - count - 1 == n - i) {
      // cout << "ho(" << m << ' ' << count + 1 << ' ' << n << ' ' << i << ") ";
      // cout << e_count << ' ';
      viable.push_back(e_count);
      max_sum = max(max_sum, sum);
      count += 1;

      for (int j = i; j < n; j++) {
        // cout << 1 << ' ';
        viable.push_back(1);
        count += 1;
      }
      sum = 0;
      break;
    }

    if (sum + arr[i] > target) {
      // cout << e_count << ' ';
      viable.push_back(e_count);
      max_sum = max(max_sum, sum);
      count += 1;
      sum = arr[i];
      e_count = 1;
    } else {
      sum += arr[i];
      e_count += 1;
    }
  }
  if (sum > 0) {
    // cout << e_count << ' ';
    viable.push_back(e_count);
    max_sum = max(max_sum, sum);
    count += 1;
  }

  if (count == m) {
    return max_sum;
  } else if (count > m) {
    return -1;
  } else {
    return -2;
  }
}

void solution(int s, int e) {
  // cout << "solution: " << s << ' ' << e << '\n';
  if (s > e) {
    return;
  }
  int mid = (s + e) / 2;
  // cout << "target: " << mid << '\n';
  int result = subprogram(mid);
  // cout << "ret: " << result << '\n';
  // cout << '\n';

  if (result != -1 && result != -2 && result < minn) {
    minn = result;
    candidate = viable;
  }
  viable.clear();

  if (s != e) {
    if (result == -1) {
      solution(mid + 1, e);
    } else if (result == -2) {
      solution(s, mid - 1);
    } else {
      solution(s, result - 1);
    }
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  solution(1, sum);

  cout << minn << '\n';
  for (int i = 0; i < candidate.size(); i++) {
    cout << candidate[i] << ' ';
  }
  cout << '\n';
}
