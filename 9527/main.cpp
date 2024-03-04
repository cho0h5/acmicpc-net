#include <iostream>

using namespace std;

void fastio() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

long long dp[60];

void init_dp() {
  dp[0] = 0;
  dp[1] = 1;
  int msb = 2;
  for (int i = 2; i < 60; i++) {
    dp[i] = dp[i - 1] * 2 + msb;
    msb *= 2;
  }
}

long long up(long long b, int flag) {
  int i = 59;
  long long one_count = 0;
  long long count = 0;
  long long mask = 1L << i;
  while (i >= 0) {
    if (b & mask) {
      count += dp[i];
      count += mask * one_count;
      count += flag;
      one_count++;
    }

    i--;
    mask = 1L << i;
  }
  return count;
}

int main() {
  fastio();
  init_dp();
  long long a, b;
  cin >> a;
  cin >> b;
  a = up(a, 0);
  b = up(b, 1);

  for (int i = 0; i < 55; i++) {
    cout << dp[i] << ' ';
  }
  cout << '\n';
  cout << "a: " << a << '\n';
  cout << "b: " << b << '\n';

  cout << b - a << '\n';
}
