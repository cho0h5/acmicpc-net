#include <iostream>
#include <vector>

#define LIMIT (4000000)

using namespace std;

int sieve[LIMIT];
vector<int> primes;

int main() {
  sieve[0] = -1;
  sieve[1] = -1;
  for (int i = 0; i < LIMIT; i++) {
    if (sieve[i] == -1)
      continue;

    primes.push_back(i);
    for (int j = i << 1; j < LIMIT; j += i) {
      sieve[j] = -1;
    }
  }

  int n;
  cin >> n;
  int count = 0;

  int i = 0;
  int j = 0;
  int state = primes[0];
  while (j < primes.size()) {
    if (state == n)
      count++;

    if (state < n) {
      j++;
      if (j < primes.size())
        state += primes[j];
    } else {
      state -= primes[i];
      i++;
    }
  }

  cout << count;
  cout << '\n';
}
