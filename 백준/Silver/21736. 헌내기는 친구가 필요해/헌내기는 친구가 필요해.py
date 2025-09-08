import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())
field = [input() for _ in range(n)]
visited = [[False]*m for _ in range(n)]

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]
count = 0

def is_valid(x, y):
    return 0 <= x < n and 0 <= y < m and not visited[x][y]

def dfs(x, y):
    global count
    visited[x][y] = True
    if field[x][y] == 'P':
        count += 1
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if is_valid(nx, ny) and field[nx][ny] != 'X':
            dfs(nx, ny)

# 시작 위치 찾기
for i in range(n):
    for j in range(m):
        if field[i][j] == 'I':
            si, sj = i, j

dfs(si, sj)
print(count if count > 0 else "TT")