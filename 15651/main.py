ns = [1, 2, 3, 4, 5, 6, 7]
from itertools import product

n, m = map(int, input().split())

result = list(product(ns[:n], repeat=m))

for e in result:
    for ee in e:
        print(ee, end=" ")
    print()