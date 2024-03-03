#include <iostream>

using namespace std;

int n, s;
int arr[100001];

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int i = 0;
  int j = 0;
  int state = arr[0];
  int minn = 999999999;
  while (j < n) {
    if (state < s) {
      j++;
      state += arr[j];
    } else {
      minn = min(minn, j - i + 1);

      state -= arr[i];
      i++;
    }
  }
  if (minn != 999999999)
    cout << minn << '\n';
  else
    cout << "0\n";
}
