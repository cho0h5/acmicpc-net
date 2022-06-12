n, k = map(int, input().split())

# 1 2 3 4 5 6 7
ns = []
for i in range(1, n + 1):
    ns.append(str(i))

k -= 1
i = 0

result = []

for _ in range(n):
    i += k
    i %= len(ns)
    result.append(ns[i])

    del ns[i]

print("<{}>".format(', '.join(result)))