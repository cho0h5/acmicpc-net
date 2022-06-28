n, m, r = map(int, input().split())
import sys
import sys
sys.setrecursionlimit(10**9)
graph = {}
for i in range(1, n + 1):
    graph[i] = []
for _ in range(m):
    s, d = map(int, sys.stdin.readline()[:-1].split())
    graph[s].append(d)
    graph[d].append(s)

for key in graph:
    graph[key].sort()

visited = [0] * (n+1)
count = 1

def dfs(n):
    global count
    global visited
    if visited[n] == 0:
        visited[n] = count
        count += 1
        for i in graph[n]:
                dfs(i)

dfs(r)
visited = list(map(str, visited))
print('\n'.join(visited[1:]))