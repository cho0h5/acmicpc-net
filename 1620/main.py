import sys

n, m = map(int, input().split())
ns1 = {}
ns2 = {}
for i in range(1, n + 1):
    ns1[i] = sys.stdin.readline() 
    ns2[ns1[i]] = i

ms = []
for _ in range(m):
    ms.append(sys.stdin.readline())

for p in ms:
    try:
        print(ns1[int(p)].strip())
    except:
        print(ns2[p])

