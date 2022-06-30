s, d = map(int, input().split())

# global
INF = 1000000
cost = [INF] * 100101

# initialize
cost[s] = 0

# solution
from collections import deque
def search():
    q = deque([s-1, s+1, s*2])
    while q:
        n = q.popleft()
        if n > 100010 or n < 0:
            continue
        m = 0
        if n % 2 == 0:
            m = min(cost[n-1]+1, cost[n+1]+1, cost[n//2])
        else:
            m = min(cost[n-1]+1, cost[n+1]+1)
        if cost[n] > m:
            cost[n] = m
            q.extend([n-1, n+1, n*2])

# out
search()
# print("debug:", cost[0:40])
print(cost[d])