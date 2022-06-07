def f(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

def checkzero(n):
    n = list(reversed(str(n)))
    for i in range(len(n)):
        if n[i] != "0":
            return i

print(checkzero(f(int(input()))))