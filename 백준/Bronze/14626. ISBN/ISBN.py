isbn = list(input())
m = int(isbn[-1])
damaged = isbn.index('*')

check = 0
for idx, num in enumerate(isbn[:12]):
    if idx == damaged:
        continue
    elif idx%2 == 0:
        check+=int(num)
    else:
        check+=int(num)*3

result = 0
weight = 1 if damaged%2 == 0 else 3
for i in range(10):
    compNum = (check+i*weight) % 10
    if compNum == 0 and m == 0:
        result = i
        break
    elif 10-compNum == m:
        result = i
print(result)