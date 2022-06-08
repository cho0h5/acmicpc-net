n = int(input())

i = 1
j = 1

for _ in range(2, n + 1):
    k = i
    i += j
    j = k

    i %= 15746
    j %= 15746

print(i)