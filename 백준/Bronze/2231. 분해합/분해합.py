n = int(input())
summoner = 0
for i in range(n-1, 0, -1):
    add = 0
    for j in str(i):
        add += int(j)
    if (i + add) == n:
        summoner = i
    if i < (n // 2):
        break
print(summoner)