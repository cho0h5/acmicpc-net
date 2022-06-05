n = int(input())
ns = list(map(int, input().split()))
nss = sorted(ns)

dic = {}
count = 0
for e in range(1, len(nss)):
    if nss[e-1] != nss[e]:
        dic[nss[e-1]] = count
        count += 1
dic[nss[-1]] = count

for e in ns:
    print(dic[e], end=' ')