import heapq
import sys
input = sys.stdin.readline

V, E = map(int, input().split())

graph = {i:[] for i in range(1, V+1)}

min_cost = [float('inf')] * (V+1)

queue = []
heapq.heapify(queue)

start = int(input())
min_cost[start] = 0

for _ in range(E):
    u, v, weight = map(int, input().split())
    graph[u].append((weight, v))

heapq.heappush(queue, (0, start))
while queue:
    weight, node = heapq.heappop(queue)
    if min_cost[node] < weight: continue
    for w, vertex in graph[node]:
        new_cost = min_cost[node] + w
        if min_cost[vertex] > new_cost:
            min_cost[vertex] = new_cost
            heapq.heappush(queue, (new_cost, vertex))

output = []
for i in range(1, V+1):
    if min_cost[i] != float('inf'):
        output.append(min_cost[i])
    else: output.append('INF')
print('\n'.join(map(str, output)))