n = int(input())
ns = []
import sys
for _ in range(n):
    ns.append(list(map(int, sys.stdin.readline().split())))

def max_parent(step, i):
    left_parent = ns[step-1][i-1]
    try:
        right_parent = ns[step-1][i]
    except:
        return left_parent

    if i == 0:
        return right_parent
    return max(left_parent, right_parent)

def search():
    for step in range(1, n):
        for i in range(step + 1):
            ns[step][i] += max_parent(step, i)        
    
search()
ns[-1].sort()
print(ns[-1][-1])