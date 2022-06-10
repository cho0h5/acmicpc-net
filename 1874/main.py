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

max_num = max(ns)

stack1 = []
stack2 = []
for num in ns:
    if len(stack1) > 0 and stack1[-1] == max_num:
        stack2.append(stack1.pop())
        print("-")
        max_num -= 1

    if num == max_num:
        print("+\n-")
        stack2.append(num)
        max_num -= 1
    else:
        stack1.append(num)
        print("+")
print(len(stack1))
print(isSorted(stack1) and isSorted(stack2))