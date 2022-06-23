import sys
sys.setrecursionlimit(10**9)

n, m = map(int, sys.stdin.readline()[:-1].split())
ms = {}
for i in range(1, n+1):
    ms[i] = []

for _ in range(m):
    a, b = map(int, sys.stdin.readline()[:-1].split())
    if a == b:
        continue
    ms[b].append(a)

# print(ms)

search_table = [1] * n
def search(i):
    if i not in ms.keys():
        return search_table[i-1]

    if search_table[i-1] != 1:
        return search_table[i-1]

    result = 1
    for j in ms[i]:
        result += search(j)
    search_table[i-1] = result
    return search_table[i-1]

for i in range(1, n + 1):
    search_table[i-1] = search(i)

# print(search_table)

max_count = max(search_table)
for i in range(n):
    if search_table[i] == max_count:
        print(i + 1, end=" ")