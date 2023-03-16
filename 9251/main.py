def printTable(table):
    for line in table:
        print(line)


S1 = input()
S2 = input()

dp = [[0] * (len(S1) + 1) for _ in range(len(S2) + 1)]

for i in range(1, len(S1) + 1):
    for j in range(1, len(S2) + 1):
        if S1[i-1] == S2[j-1]:
            dp[j][i] = dp[j-1][i-1] + 1
        else:
            dp[j][i] = max(dp[j-1][i], dp[j][i-1])

print(dp[-1][-1])