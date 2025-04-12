a, b, c = map(int, input().split())
count = a // (c - b) + 1 if b < c else -1
print(count)