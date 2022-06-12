import sys
from collections import deque

print = sys.stdout.write

t = int(input())
for _ in range(t):
    # each testcase
    direction = 0
    funcs = list(sys.stdin.readline().strip())    # like ['R', 'D', 'D']
    n = int(sys.stdin.readline()[:-1])
    ns = sys.stdin.readline()[1:-2].split(",")
    if n == 0:
        ns = deque()
    else:
        ns = deque(map(int, ns))

    flag = True
    for func in funcs:
        if func == "D":
            if len(ns) == 0:
                flag = False
                break
            if direction == 0:
                ns.popleft()
            else:
                ns.pop()
        elif func == "R":
            direction = 1 - direction

    if flag:
        ns = list(map(str, ns))
        if direction == 0:
            print("[")
            for i in range(len(ns) - 1):
                print(ns[i])
                print(",")
            if len(ns) != 0:
                print(ns[-1])
            print("]\n")
        else:
            print("[")
            for i in range(len(ns) - 1, 0, -1):
                print(ns[i])
                print(",")
            if len(ns) != 0:
                print(ns[0])
            print("]\n")
    else:
        print("error\n")