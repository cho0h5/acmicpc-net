import sys
n, m = map(int, sys.stdin.readline().split())
ns = list(map(int, sys.stdin.readline().split()))
ms = []
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    ms.append([a-b, a, b])
ms.sort()

def search(x, y):
    for i in range(m):
        if x <= ms[i][1] and y <= ms[i][2]:
            try:
                ms[i][3]
                return ...
            except:
                pass
    return sum(...)


def solution():
    for i in range(m):
        ms[i].append(search(ms[i][1], ms[i][2]))
