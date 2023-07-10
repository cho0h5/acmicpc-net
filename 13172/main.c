#include <stdio.h>
#include <math.h>
#define MOD 1000000007

long long modpow(long long base, int exp, int modulus) {
  base %= modulus;
  long long result = 1;
  while(exp > 0) {
    if(exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }

  return result;
}

int gcd(int a, int b) {
  while(b != 0) {
    int temp = a % b;
    a = b;
    b = temp;
  }

  return a;
}

void reduceFraction(long long *a, long long *b) {
  int gcd_result = gcd(*a, *b);
  *a /= gcd_result;
  *b /= gcd_result;
}

int main() {
  int M;
  scanf("%d", &M);

  long long S = 0;
  long long N = 1;
  while(M--) {
    long long n, s;
    scanf("%lld %lld", &n, &s);

    S = S * n + N * s;
    N = N * n;
    reduceFraction(&S, &N);
  }
  long long result = (S * modpow(N, MOD - 2, MOD)) % MOD;
  printf("%lld\n", result);
}
