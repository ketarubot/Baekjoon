n, k = map(int, input().split())
x = list(map(int, input().split()))
for i in range(n):
    min_idx = i
    for j in range(i, n):
        if x[min_idx] > x[j]:
            min_idx = j
    x[i], x[min_idx] = x[min_idx], x[i]
print(x[-k])