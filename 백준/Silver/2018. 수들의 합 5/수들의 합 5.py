n = int(input())
count = 0
for i in range(1, n+1):
    x = n - ((i*(i-1))//2)
    if x%i == 0 and x > 0:
        count += 1
print(count)