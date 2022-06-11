def isSorted(arr):
    flag = True
    for i in range(1, len(arr)):
        if arr[i-1] < arr[i]:
            flag = False
    return flag

import sys
n = int(input())
ns = []
for _ in range(n):
    ns.append(int(sys.stdin.readline().strip()))

stack = []
count = 1
idx = 0
flag = True
result = []
while True:
    num = ns[idx]
    if len(stack) > 0 and stack[-1] == num:
        stack.pop()
        result.append("-")
        idx += 1
    else:
        stack.append(count)
        count += 1
        result.append("+")

    if idx == len(ns):
        break
    if count > len(ns) + 1:
        flag = False
        break
        

if flag:
    print("\n".join(result))
else:
    print("NO")