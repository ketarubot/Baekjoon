from sys import stdin
input = stdin.readline

c = int(input())
for _ in range(c):
    n, *scores = map(int, input().split())
    avg = sum(scores) / n
    count = 0
    for i in scores:
        if i > avg:
            count += 1
    print(f'{count / n * 100:.3f}%')