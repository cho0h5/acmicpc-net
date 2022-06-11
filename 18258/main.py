from collections import deque
n = int(input())
import sys
print = sys.stdout.write
queue = deque()
for _ in range(n):
    command = sys.stdin.readline().split()
    if len(command) == 2:
        command[1] = int(command[1])

    # start
    if command[0] == "push":
        queue.append(command[1])
    elif command[0] == "pop":
        if len(queue) == 0:
            print("-1\n")
            continue
        print("{}\n".format(queue.popleft()))
    elif command[0] == "size":
        print("{}\n".format(len(queue)))
    elif command[0] == "empty":
        print("{}\n".format(1 if len(queue) == 0 else 0))
    elif command[0] == "front":
        print("{}\n".format(queue[0] if len(queue) != 0 else -1))
    elif command[0] == "back":
        print("{}\n".format(queue[-1] if len(queue) != 0 else -1))