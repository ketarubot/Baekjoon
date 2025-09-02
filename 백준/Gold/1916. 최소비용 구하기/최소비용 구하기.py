import sys
import heapq
input = sys.stdin.readline
hpush = heapq.heappush
hpop = heapq.heappop

n = int(input())
m = int(input())

graph = {i:[] for i in range(1, n+1)}
for _ in range(m):
    start, end, cost = map(int, input().split())
    graph[start].append((cost, end))

start, end = map(int, input().split())
min_cost = [float('inf')] * (n+1)
min_cost[start] = 0
queue = []
heapq.heapify(queue)
hpush(queue, (0, start))
while queue:
    cost, node = hpop(queue)
    if min_cost[node] < cost: continue
    for weight, vertex in graph[node]:
        new_cost = min_cost[node] + weight
        if min_cost[vertex] > new_cost:
            min_cost[vertex] = new_cost
            hpush(queue, (new_cost, vertex))

print(min_cost[end])