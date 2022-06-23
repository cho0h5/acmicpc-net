n = int(input())
distances = list(map(int, input().split()))
prices = list(map(int, input().split()))

# print(n, distances, prices)

# solution
new_prices = [prices[0]]
for i in range(1, n):
    if prices[i] < new_prices[i-1]:
        new_prices.append(prices[i])
    else:
        new_prices.append(new_prices[-1])
# print(new_prices)

result = 0
for i in range(n-1):
    result += distances[i] * new_prices[i]

print(result)