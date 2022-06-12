from collections import deque
n = int(input())
import sys
queue = deque()
for _ in range(n):
    command = sys.stdin.readline().split()
    if len(command) == 2:
        n = int(command[1])
    c = command[0]

    # start
    if c == "push_front":
        queue.appendleft(n)
    elif c == "push_back":
        queue.append(n)
    elif c == "pop_front":
        print(queue.popleft() if len(queue) != 0 else -1)
    elif c == "pop_back":
        print(queue.pop() if len(queue) != 0 else -1)
    elif c == "size":
        print(len(queue))
    elif c == "empty":
        print(1 if len(queue) == 0 else 0)
    elif c == "front":
        print(queue[0] if len(queue) != 0 else -1)
    elif c == "back":
        print(queue[-1] if len(queue) != 0 else -1)