# input
n = int(input())
import sys

ns = []
for _ in range(n):
    ns.append(int(sys.stdin.readline()))

# start
result = []
for i in range(2, max(ns)):
    flag = True
    remain = ns[0] % i
    for e in ns:
        if e % i != remain:
            flag = False
            break

    if flag == True:
        result.append(i)

print(' '.join(map(str, result)))