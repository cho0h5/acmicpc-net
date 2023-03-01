N, M = map(int, input().split())
boxes = [0] * N

for _ in range(M):
    i, j, k = map(int, input().split())
    for index in range(i - 1, j):
        boxes[index] = k

boxes = list(map(str, boxes))
print(' '.join(boxes))