n = int(input())
result = 0

r1 = [True] * n
r2 = [True] * (n * 2 - 1)
r3 = [True] * (n * 2 - 1)

def rec(step):
    global result
    if step == n:
        result += 1

    for i in range(n):
        if r1[i] and r2[step + i] and r3[n + step - i - 1]:
            r1[i] = r2[step + i] = r3[n + step - i - 1] = False
            rec(step + 1)
            r1[i] = r2[step + i] = r3[n + step - i - 1] = True

rec(0)

print(result)