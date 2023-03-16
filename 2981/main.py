from math import gcd
from math import ceil
from math import sqrt

N = int(input())
ns = []
for _ in range(N):
    ns.append(int(input()))

dn = []
for i in range(N-1):
    dn.append(ns[i+1] - ns[i])

_gcd = dn[0]
for i in range(N-2):
    _gcd = gcd(_gcd, dn[i+1])

divisors = set()
for i in range(1, ceil(sqrt(_gcd)) + 1):
    if _gcd % i == 0:
        divisors.add(i)
        divisors.add(_gcd // i)

divisors.remove(1)

print(' '.join(map(str, sorted(list(divisors)))))
