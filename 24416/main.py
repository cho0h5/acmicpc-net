dpt = [0] * 41
dpt[1] = 1
dpt[2] = 1

def fib(n):
    if dpt[n] != 0:
        return dpt[n]
    
    dpt[n] = fib(n-2) + fib(n-1)
    return dpt[n]

n = int(input())

print(fib(n), n - 2)