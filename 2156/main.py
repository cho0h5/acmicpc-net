N = int(input())
ns = []
for _ in range(N):
    ns.append(int(input()))

dp = [0] * N

# print(ns)

dp[0] = (ns[0], ns[0])
if N >= 2:
    dp[1] = (ns[1], ns[0] + ns[1])
if N >= 3:
    dp[2] = (ns[0] + ns[2], ns[1] + ns[2])
if N >= 4:
    dp[3] = (dp[1][1] + ns[3], ns[0] + ns[2] + ns[3])

for i in range(4, N):
    dp[i] = (
        max(max(dp[i-3]) + ns[i],
            max(dp[i-2]) + ns[i]),
        max(max(dp[i-4]) + ns[i-1] + ns[i],
            max(dp[i-3]) + ns[i-1] + ns[i])
    )

# print(dp)

if N == 1:
    print(ns[0])
else:
    print(max(dp[-2][0], dp[-2][1], dp[-1][0], dp[-1][1]))