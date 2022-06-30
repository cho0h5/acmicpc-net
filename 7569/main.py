import sys
from collections import deque
m, n, h = map(int, input().split())

array = [[0] * n for _ in range(h)]

for i in range(h):
    for j in range(n):
        array[i][j] = list(map(int, sys.stdin.readline()[:-1].split()))

# solution
def check_done():
    global array
    for i in range(h):
        for j in range(n):
            for k in range(m):
                if array[i][j][k] == 0:
                    return False
    return True

def search():
    global h, m, n
    count = 0
    q = deque()
    for i in range(h):
        for j in range(n):
            for k in range(m):
                if array[i][j][k] == 1:
                    q.append((i, j, k))
    while q:
        # check done
        if check_done():
            return count

        q_tmp = q
        q = deque()
        for nd in q_tmp:
            for i in range(max(0, nd[0]-1), min(nd[0]+2, h)):
                if array[i][nd[1]][nd[2]] == 0:
                    array[i][nd[1]][nd[2]] = 1
                    q.append((i, nd[1], nd[2]))
            for j in range(max(0, nd[1]-1), min(nd[1]+2, n)):
                if array[nd[0]][j][nd[2]] == 0:
                    array[nd[0]][j][nd[2]] = 1
                    q.append((nd[0], j, nd[2]))
            for k in range(max(0, nd[2]-1), min(nd[2]+2, m)):
                if array[nd[0]][nd[1]][k] == 0:
                    array[nd[0]][nd[1]][k] = 1
                    q.append((nd[0], nd[1], k))
        count += 1
# run
count = search()
print(count if check_done() else -1)
