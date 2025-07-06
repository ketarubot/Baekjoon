from collections import deque
from sys import stdin
input = stdin.readline

n, m = map(int, input().split())
graph = {i:[] for i in range(1, n+1)}
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
bacon = [float('inf')] * (n+1)

def bfs(graph, start):
    queue = deque([(start, 0)])
    visited = [False] * (n+1)
    visited[start] = True
    num = 0
    while queue:
        user, relation = queue.popleft()
        num += relation
        for friend in graph[user]:
            if not visited[friend]:
                queue.append((friend, relation+1))
                visited[friend] = True
    bacon[start] = num

for i in range(1, n+1):
    bfs(graph, i)
print(bacon.index(min(bacon)))