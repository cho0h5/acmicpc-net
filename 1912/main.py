n = int(input())
ns = list(map(int, input().split()))

table = [ns[0]]

tmp = ns[0]
for i in range(1, n):
    tmp = table[i - 1] + ns[i]
    if tmp > ns[i]:
        table.append(tmp)
    else:
        table.append(ns[i])

table.sort()
print(table[-1])