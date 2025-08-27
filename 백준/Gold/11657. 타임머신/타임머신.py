n, m = map(int, input().split())

dist = [float('inf')] * (n+1)
dist[1] = 0

edges = []
for _ in range(m):
    start, end, time = map(int, input().split())
    edges.append((start, end, time))

for _ in range(n-1):
    for u, v, w in edges:
        if dist[u] != float('inf') and dist[v] > dist[u] + w:
            dist[v] = dist[u] + w

negative_cycle = False
for u, v, w in edges:
    if dist[u] != float('inf') and dist[v] > dist[u] + w:
        negative_cycle = True
        break

if negative_cycle: print(-1)
else:
    output = []
    for i in range(2, n+1):
        if dist[i] != float('inf'):
            output.append(dist[i])
        else: output.append(-1)
    print('\n'.join(map(str, output)))