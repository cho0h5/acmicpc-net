import sys

n, m = map(int, sys.stdin.readline()[:-1].split())
ms = {}

for _ in range(m):
    a, b = map(int, sys.stdin.readline()[:-1].split())
    if b in ms.keys():
        ms[b].append(a)
    else:
        ms[b] = [a]

# print(ms)

def search(i):
    if i not in ms.keys():
        return 1
    result = 1
    for j in ms[i]:
        result += search(j)
    return result

results = []
for i in range(1, n + 1):
    results.append(search(i))

# print(results)

max_count = max(results)
for i in range(n):
    if results[i] == max_count:
        print(i + 1, end=" ")