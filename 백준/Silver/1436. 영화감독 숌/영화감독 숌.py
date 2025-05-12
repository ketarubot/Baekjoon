n = int(input())
i = 1
num = 666
while i < n:
    num += 1
    while not '666' in str(num):
        num += 1
    i += 1
print(num)