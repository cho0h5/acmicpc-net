import sys
input = sys.stdin.readline

result = []
n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    result.append(str(a + b))

print('\n'.join(result))