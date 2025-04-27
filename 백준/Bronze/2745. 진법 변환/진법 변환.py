n, b = input().split()
b = int(b)
deci = 0
for weight, num in enumerate(n[::-1]):
    if num.isalpha():
        deci += (ord(num) - 55) * b**weight
    else:
        deci += int(num) * b**weight
print(deci)
