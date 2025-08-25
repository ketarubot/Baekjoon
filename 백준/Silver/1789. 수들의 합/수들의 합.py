n = int(input())

s = 0
num = 1
count = 0
while True:
    s += num
    num += 1
    if s > n: break
    count += 1
print(count)