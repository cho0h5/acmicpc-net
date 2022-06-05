from itertools import combinations

s = list(input())
se = set()
for i in range(len(s)):
    for j in range(len(s)):
        se.add(''.join(s[i:j + 1]))

print(len(se) - 1)