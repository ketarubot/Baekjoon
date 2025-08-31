from collections import deque

def is_valid(cx, cy):
    if mx > cx >= 0 and my > cy >= 0:
        return True
    return False

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
vectors = 4
queue = deque([])

mx: int
my: int
for _ in range(int(input())):
    mx, my, k = map(int, input().split())

    field = [[0] * mx for r in range(my)]

    for pos in range(k):
        x, y = map(int, input().split())
        field[y][x] = 1

    count = 0
    visited = [[False] * mx for r in range(my)]
    for i in range(my):
        for j in range(mx):
            if field[i][j] and not visited[i][j]:
                count += 1
                queue.append((j, i))
                visited[i][j] = True

                while queue:
                    x, y = queue.popleft()

                    for d in range(vectors):
                        next_x = x + dx[d]
                        next_y = y + dy[d]

                        if is_valid(next_x, next_y) and field[next_y][next_x] and not visited[next_y][next_x]:
                            queue.append((next_x, next_y))
                            visited[next_y][next_x] = True

    print(count)