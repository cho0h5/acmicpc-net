import math 
from itertools import permutations
n = int(input())
ns = list(map(int, input().split()))
a, s, m, d = map(int, input().split())

operators = []
operators.extend(["+" for _ in range(a)])
operators.extend(["-" for _ in range(s)])
operators.extend(["*" for _ in range(m)])
operators.extend(["/" for _ in range(d)])

ps = list(permutations(operators, n - 1))

_min = 1000000000
_max = -1000000000

for p in ps:
    num = ns[0]
    # print(p)
    for i in range(n - 1):
        if p[i] == "+":
            num += ns[i+1]
        elif p[i] == "-":
            num -= ns[i+1]
        elif p[i] == "*":
            num *= ns[i+1]
        else:
            num /= ns[i+1]
            num = math.floor(num) if num > 0 else math.ceil(num)

    _max = max(_max, num)
    _min = min(_min, num)

print(_max)
print(_min)
