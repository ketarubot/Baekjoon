N = input()
count = [0] * 10

for num in N:
    n = int(num)
    if n == 6:
        if count[6] > count[9]:
            count[9] += 1
        else:
            count[6] += 1
    elif n == 9:
        if count[9] > count[6]:
            count[6] += 1
        else:
            count[9] += 1
    else:
        count[n] += 1
print(max(count))