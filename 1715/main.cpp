#include <iostream>
#include <set>

using namespace std;

multiset<int> ms;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ms.insert(x);
  }

  int result = 0;
  if (n == 1) {
    cout << "0\n";
    return 0;
  }

  while (ms.size() >= 2) {
    auto it1 = ms.begin();
    int b1 = *it1;
    ms.erase(it1);
    auto it2 = ms.begin();
    int b2 = *it2;
    ms.erase(it2);
    int s = b1 + b2;
    result += s;
    ms.insert(s);
  }
  cout << result << '\n';
  return 0;
}
