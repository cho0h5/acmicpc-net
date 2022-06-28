import sys
sys.setrecursionlimit(10**9)

n, m, r = map(int, input().split())
graph = {}
for i in range(n+1):
    graph[i] = []
for _ in range(m):
    u, v = map(int, sys.stdin.readline()[:-1].split())
    graph[u].append(v)
    graph[v].append(u)
for i in range(n+1):
    graph[i].sort()

# solution
from collections import deque

visited = [0] * (n+1)
queue = deque()
queue.append(r)

count = 2
visited[r] = 1

while True:
    try:
        v = queue.popleft()
    except:
        break

    for child in graph[v]:
        if visited[child] == 0:
            visited[child] = count
            count += 1
            queue.append(child)
        
visited = list(map(str, visited))
print(' '.join(visited[1:]))