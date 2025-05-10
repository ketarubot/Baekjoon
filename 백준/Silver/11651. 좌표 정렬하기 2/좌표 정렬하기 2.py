from sys import stdin
input = stdin.readline

n = int(input())
locations = dict()
for _ in range(n):
    x, y = map(int, input().split())
    if locations.get(y, False):
        locations[y].append(x)
    else:
        locations[y] = [x]

miny = min(locations.keys())
maxy = max(locations.keys()) + 1
for y in range(miny, maxy):
    if locations.get(y, False):
        locations[y].sort()
        for x in locations[y]:
            print(x, y)

       