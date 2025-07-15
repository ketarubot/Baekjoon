n = int(input())
arr = [True] * (n+1)
for i in range(2, n+1):
    if arr[i]:
        for j in range(i*2, n+1, i):
            arr[j] = False
prime = [i for i in range(2, n+1) if arr[i]]

start = 0
end = 1
count = 0
while end <= len(prime):
    h = sum(prime[start:end])
    if h < n:
        end += 1
    elif h > n:
        start += 1
    else:
        count += 1
        start += 1
print(count)