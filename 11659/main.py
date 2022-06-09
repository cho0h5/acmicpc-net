import sys
n, m = map(int, sys.stdin.readline().split())
ns = [0]
ns.extend(list(map(int, sys.stdin.readline().split())))

for i in range(1, n+1):
    ns[i] += ns[i-1]

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())

    print(ns[b] - ns[a-1])