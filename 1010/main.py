def C(n, m):
    result = 1
    for i in range(n - m + 1, n + 1):
        result *= i
    for i in range(1, m + 1):
        result = result // i

    return result

t = int(input())
import sys

for _ in range(t):
    m, n = map(int, sys.stdin.readline().split())

    print(C(n, m))