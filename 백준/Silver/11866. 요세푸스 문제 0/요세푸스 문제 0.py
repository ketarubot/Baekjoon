n, k = map(int, input().split())
circle = list(range(1, n+1))
yosep = list()
while circle:
    idx = (k-1) % len(circle)
    yosep.append(circle.pop(idx))
    circle = circle[idx:] + circle[:idx]
print('<'+', '.join(map(str, yosep))+'>')