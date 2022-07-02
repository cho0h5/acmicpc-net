import sys
input = sys.stdin.readline

n = int(input())
paper = [0] * n
for i in range(n):
    paper[i] = list(map(int, input().split()))

def log3(n):
    for exp in range(8):
        if 3 ** exp == n:
            return exp

n = log3(n)

def check(level, x, y):
    global paper
    px = x
    py = y
    x = x * (3 ** (level + 1))
    y = y * (3 ** (level + 1))
    ix = x * (3 ** level)
    iy = y * (3 ** level)

    flag = True
    state = paper[ix][iy]
    for i in range(3):
        for j in range(3):
            # if level == 1: print(ix+i* (3 ** level), iy+j* (3 ** level)) # debug
            if state != paper[ix + i* (3 ** level)][iy + j* (3 ** level)] or paper[ix+i* (3 ** level)][iy+j* (3 ** level)] == 999:
                flag = False
    
    if flag:
        return state
    else:
        count(level, px, py)
        paper[ix][iy] = 999
        return 999 # fail

c = [0, 0, 0]
def count(level, x, y):
    global paper
    global c
    x = x * (3 ** (level + 1))
    y = y * (3 ** (level + 1))
    ix = x * (3 ** level)
    iy = y * (3 ** level)
    
    for i in range(3):
        for j in range(3):
            state = paper[ix+i* (3 ** level)][iy+j* (3 ** level)]
            if state == 999:
                continue
            c[state + 1] += 1

if n == 0:
    c[paper[0][0]+1] += 1
    c = map(str, c)
    print('\n'.join(c))
    sys.exit()

for l in range(n - 1):
    for i in range(3):
        for j in range(3):
            state = check(l, i, j)

check(n-1, 0, 0)

c = map(str, c)
print('\n'.join(c))