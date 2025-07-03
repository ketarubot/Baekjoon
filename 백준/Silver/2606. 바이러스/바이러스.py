from collections import deque

n = int(input())
p = int(input())
graph = {}

for _ in range(p):
    a, b = map(int, input().split())
    if graph.get(a, False):
        graph[a].add(b)
    else:
        graph[a] = {b}
    if graph.get(b, False):
        graph[b].add(a)
    else:
        graph[b] = {a}

qu = deque([1])
done = {1}
while qu:
    current = qu.popleft()
    for computer in graph.get(current, {}):
        if computer not in done:
            qu.append(computer)
            done.add(computer)
print(len(done)-1)