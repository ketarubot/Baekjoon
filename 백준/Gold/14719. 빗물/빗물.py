h, w = map(int, input().split())
blocks = list(map(int, input().split()))
world = [[0 for j in range(w)] for i in range(h)]
for i in range(h):
    for j in range(w):
        if blocks[j] > i:
            world[h-i-1][j] = 1

count = 0
for i in range(h):
    wall = [-1, -1]
    for j in range(w):
        if world[i][j] == 1:
            if wall[0] == -1: wall[0] = j
            wall[1] = j
    for j in range(w):
        if world[i][j] == 0 and wall[0] < j < wall[1]:
            count += 1
print(count)