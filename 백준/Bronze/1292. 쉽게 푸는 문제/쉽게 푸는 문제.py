a, b = map(int, input().split())
seq = []
count = 1
while True:
    for i in range(count):
        seq.append(count)
        b -= 1
        if b <= 0:
            break
    if b <= 0:
        break
    count += 1
print(sum(seq[a-1:]))