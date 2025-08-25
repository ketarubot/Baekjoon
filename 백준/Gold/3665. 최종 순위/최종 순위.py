from sys import stdin
from collections import deque
f_input = stdin.readline

for _ in range(int(input())):
    n = int(f_input())
    past_rank = [0] + list(map(int, f_input().split()))

    graph = {i:[] for i in range(1, n+1)}
    in_degree = [0] * (n+1)
    for i in range(1, n+1):
        for j in range(i+1, n+1):
            u = past_rank[i]
            v = past_rank[j]
            graph[u].append(v)
            in_degree[v] += 1

    m = int(f_input())

    for loop in range(m):
        a, b = map(int, f_input().split())

        if b in graph[a]:
            graph[a].remove(b)
            in_degree[b] -= 1
            graph[b].append(a)
            in_degree[a] += 1
        else:
            graph[b].remove(a)
            in_degree[a] -= 1
            graph[a].append(b)
            in_degree[b] += 1

    queue = deque([])
    for i in range(1, n + 1):
        if in_degree[i] == 0:
            queue.append(i)

    result = []
    is_certain = True
    for _ in range(n):
        if not queue:
            break
        if len(queue) >= 2:
            is_certain = False
            break

        vertex = queue.popleft()
        result.append(vertex)

        for node in graph[vertex]:
            in_degree[node] -= 1
            if in_degree[node] == 0:
                queue.append(node)

    if not is_certain:
        print("?")
    elif len(result) < n:
        print("IMPOSSIBLE")
    else:
        print(*result)