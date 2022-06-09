# global
dict = {}

# input
import sys
s = input()
n = int(input())

# func
def update(char):
    dict[char] = [0]
    for i in range(len(s)):
        if s[i] == char:
            dict[char].append(dict[char][-1] + 1)
        else:
            dict[char].append(dict[char][-1])

# case
for _ in range(n):
    c, i, j = sys.stdin.readline().split()
    i, j = int(i), int(j)

    #solution
    if c not in dict.keys():
        update(c)

    print(dict[c][j+1] - dict[c][i])