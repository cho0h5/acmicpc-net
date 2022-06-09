import sys
n = int(input())
for _ in range(n):
    s = sys.stdin.readline()

    # solution
    flag = "YES"
    stack = 0
    for c in s:
        if c == "(":
            stack += 1
        if c == ")" and stack == 0:
            flag = "NO"
            break
        if c == ")":
            stack -= 1

    if stack != 0:
        flag = "NO"
        
    print(flag)
