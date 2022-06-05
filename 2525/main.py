h, m = map(int, input().split())
d = int(input())

m += d

import math
h += math.floor(m / 60)
m = m % 60
h = h % 24

print(h, m)