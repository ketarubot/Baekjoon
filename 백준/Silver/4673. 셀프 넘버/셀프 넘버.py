arr = [_ for _ in range(1,10001)]
count = 1
while True:
    num = count
    for _ in str(count):
        num += int(_)
    if num > 10003:
        break
    if num in arr:
        arr.remove(num)
    count += 1
for i in arr:
    print(i)