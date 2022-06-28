from collections import deque
import sys
n = int(sys.stdin.readline())
e = int(sys.stdin.readline())

graph = [[] for _ in range(n + 1)]

for _ in range(e):
    s, d = map(int, sys.stdin.readline()[:-1].split())

    graph[s].append(d)
    graph[d].append(s)

# global
count = 0

# solution
def fs():
    global count 
    q = deque([1])
    visited = [False] * (n + 1)
    visited[1] = True
    
    while q:
        v = q.popleft()
        for c in graph[v]:
            if visited[c]:
                continue
            visited[c] = True
            count += 1
            q.append(c)

fs()
print(count)