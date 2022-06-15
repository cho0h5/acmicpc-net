import sys
n = int(sys.stdin.readline()[:-1])
ns = []
for _ in range(n):
    ns.append(sys.stdin.readline()[:-1].split())

result_b = 0
result_w = 0
def quad(x, y, size):
    global result_b
    global result_w
    global ns
    if size == 1:
        return int(ns[x][y])
    
    hs = size // 2

    q1 = quad(x, y, hs)
    q2 = quad(x, y + hs, hs)
    q3 = quad(x + hs, y, hs)
    q4 = quad(x + hs, y + hs, hs)

    if q1 == q2 and q2 == q3 and q3 == q4 and q4 != -1:
        return q1
    else:
        if q1 == 0:
            result_b += 1
        elif q1 == 1:
            result_w += 1
        if q2 == 0:
            result_b += 1
        elif q2 == 1:
            result_w += 1
        if q3 == 0:
            result_b += 1
        elif q3 == 1:
            result_w += 1
        if q4 == 0:
            result_b += 1
        elif q4 == 1:
            result_w += 1

        return -1

# solution
t = quad(0, 0, n)
if t == 0:
    result_b += 1
elif t == 1:
    result_w += 1

print(result_b)
print(result_w)