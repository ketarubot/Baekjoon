n = int(input())
count = []

max3 = n // 3
max5 = n // 5

a = b = m = 0
if max3 >= max5:
    m = max3
    a = 3
    b = 5
else:
    m = max5
    a = 5
    b = 3
for i in range(m+1):
    x = n
    x -= a*i
    if x%b == 0:
        count.append(i+x//b)
    else:
        count.append(float('inf'))
result = min(count)
print(result if result != float('inf') else -1)