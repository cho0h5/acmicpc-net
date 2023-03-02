N = int(input())
ns = list(map(int, input().split()))

dp = [[1] * 2 for _ in range(N)]

for i in range(1, N):
    for j in range(i-1, -1, -1):
        if ns[i] > ns[j]:
            dp[i][0] = max(dp[i][0], dp[j][0] + 1)

for i in range(N-2, -1, -1):
    for j in range(i+1, N):
        if ns[i] > ns[j]:
            dp[i][1] = max(dp[i][1], dp[j][1] + 1)

# print(dp)

_max = 0
for i in range(N):
    _max = max(_max, sum(dp[i]))

print(_max - 1)