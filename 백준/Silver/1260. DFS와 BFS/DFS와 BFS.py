import sys
from collections import deque
sys.setrecursionlimit(10**5)

n, m, v = map(int, input().split())
graph = {i:[] for i in range(1, n+1)}
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
for i in range(1, n+1):
    graph[i].sort()

visited = [False] * (n+1)
visited[v] = True
def dfs(node):
    print(node, end=' ')
    for vertex in graph[node]:
        if not visited[vertex]:
            visited[vertex] = True
            dfs(vertex)
dfs(v)

print()

def bfs(start):
    queue = deque([start])
    visited = [False] * (n+1)
    visited[start] = True
    while queue:
        node = queue.popleft()
        print(node, end=' ')
        for vertex in graph[node]:
            if not visited[vertex]:
                queue.append(vertex)
                visited[vertex] = True
bfs(v)