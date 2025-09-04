n = int(input())
data = list(map(int, input().split()))

cost = 0
for i in range(n):
    if data[i] == 0: continue
    if i+2 < n:
        if data[i+1] > data[i+2]:
            diff = data[i+1] - data[i+2]
            k = min(data[i], diff)
            cost += k*5
            data[i+1] -= k
            data[i] -= k
        m = min(data[i], data[i+1], data[i+2])
        cost += m*7
        data[i] -= m
        data[i+1] -= m
        data[i+2] -= m
    if i+1 < n and data[i+1] > 0:
        m = min(data[i], data[i+1])
        cost += m*5
        data[i+1] -= m
        data[i] -= m
    cost += data[i]*3
    data[i] = 0
print(cost)