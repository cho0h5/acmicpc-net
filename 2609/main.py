def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

a, b = map(int, input().split())

g = gcd(a, b)
print(g)
print(a * b // g)
