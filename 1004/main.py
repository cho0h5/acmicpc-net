import sys

def isIn(coor, planet):
    cx, cy = coor
    px, py, pr = planet

    distance_square = (px - cx) ** 2 + (py - cy) ** 2

    if distance_square > pr ** 2:
        return False
    else:
        return True

t = int(input())
for _ in range(t):
    # in test case

    # input
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    ns = []
    for _ in range(n):
        x, y, r = map(int, sys.stdin.readline().strip().split())
        ns.append((x, y, r))
    
    # start
    ol = []
    for p in ns:
        ol.append(isIn((x1, y1), p))
    il = []
    for p in ns:
        il.append(isIn((x2, y2), p))

    count = 0
    for i in range(len(ns)):
        if ol[i] != il[i]:
            count += 1

    print(count)