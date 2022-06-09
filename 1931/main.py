n = int(input())
ns = []
import sys
for _ in range(n):
    start, end = map(int, sys.stdin.readline().split())
    ns.append((start, end))

ns.sort()

count = 0
start = 0
end = 0
for time in ns:
    if start <= time[0] and time[1] < end:
        start = time[0]
        end = time[1]
    elif end <= time[0]:
        count += 1
        start = time[0]
        end = time[1]
    
print(count)