from sys import stdin
input = stdin.readline

n, m = map(int, input().split())
baskets = list(range(1, n+1))

for i in range(m):
    a, b = map(int, input().split())
    baskets[a-1], baskets[b-1] = baskets[b-1], baskets[a-1]
print(' '.join(map(str, baskets)))