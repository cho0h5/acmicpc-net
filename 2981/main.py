import math
from itertools import combinations

def factorization(n):
    result = list()
    for i in range(2, n + 1):
        while True:
            if n % i == 0:
                result.append(i)
                n = n // i
            else:
                break
    return result

# input
n = int(input())
import sys

ns = []
for _ in range(n):
    ns.append(int(sys.stdin.readline()))

# start
result = set()
for r in range(0, min(ns) - 1):
    g = math.gcd(*map(lambda x: x - r, ns))
    factors = factorization(g)
    for i in range(1, len(factors) + 1):
        for cs in combinations(factors, i):
            result.add(math.prod(cs))

result -= set([1])
print(' '.join(map(str, result)))