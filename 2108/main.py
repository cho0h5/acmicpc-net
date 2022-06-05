from collections import Counter
import math
import sys

n = int(input())
ns = []
for _ in range(n):
    ns.append(int(sys.stdin.readline()))

ns.sort()


# 1
print(round(sum(ns) / n))

# 2
idx = math.floor(len(ns) / 2)
if len(ns) % 2 == 1:
    print(ns[idx])
else:
    print(ns[idx-1] + ns[idx])


# 3
counter = Counter(ns)
thres = counter.most_common()[0][1]
fs = []
for c in counter:
    if counter[c] == thres:
        fs.append(c)
fs.sort()
if len(fs) > 1:
    print(fs[1])
else:
    print(fs[0])

# 4
print(ns[-1] - ns[0])