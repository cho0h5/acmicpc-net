import sys
n = int(sys.stdin.readline()[:-1])
ns = []
for _ in range(n):
    ns.append(sys.stdin.readline()[:-1].split())

result = 0
def quad(x, y, size):
    global result
    global ns
    print('run')
    if size == 1:
        return ns[x][y]
    
    hs = size // 2

    q1 = quad(x, y, hs)
    q2 = quad(x, y + hs, hs)
    q3 = quad(x + hs, y, hs)
    q4 = quad(x + hs, y + hs, hs)

    if q1 == q1 and q2 == q3 and q3 == q4 and q4 != -1:
        return q1
    else:
        q1 = 0 if q1 == -1 else 1
        q2 = 0 if q2 == -1 else 1
        q3 = 0 if q3 == -1 else 1
        q4 = 0 if q4 == -1 else 1
        result += q1 + q2 + q3 + q4
        return -1



# solution
# quad(0, 0, n)
# result += 1 if n == 1 else 0

# t = 1 if quad(0, 0, n) != -1 else 0
# result += t

print("result1:", result)
aon = 0
result += 1 if quad(0, 0, n) != -1 else 0
# print(aon)
# result += aon

print("result2: ", result)