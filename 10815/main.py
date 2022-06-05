n = int(input())
ns = set(map(int, input().split()))
m = int(input())
ms = list(map(int, input().split()))

for m in ms:
    try:
        ns.remove(m)
        print('1', end=' ')
    except:
        print('0', end=' ')