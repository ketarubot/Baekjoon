from sys import stdin
input = stdin.readline

n = int(input())
locations = [tuple(map(int, input().split())) for _ in range(n)]
locations.sort()
for x, y in locations:
    print(x, y)