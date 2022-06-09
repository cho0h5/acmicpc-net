import sys
n, k = map(int, input().split())
ns = []
for _ in range(n):
    ns.append(int(sys.stdin.readline().strip()))

ns.reverse()

result = 0
for a in ns:
    result += k // a
    k %= a

print(result)