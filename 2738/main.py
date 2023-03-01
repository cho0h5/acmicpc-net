N, M = map(int, input().split())

xs = []
for _ in range(N):
    xs.append(list(map(int, input().split())))

ys = []
for _ in range(N):
    ys.append(list(map(int, input().split())))

for i in range(N):
    for j in range(M):
        print(xs[i][j] + ys[i][j], end=' ')
    print()