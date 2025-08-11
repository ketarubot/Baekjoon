import heapq

n, m = map(int, input().split())

graph = {i:[] for i in range(1, n+1)}
in_degree = [0] * (n+1)

for t in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    in_degree[b] += 1

queue = []
heapq.heapify(queue)

i = 1
for i in range(1, n+1):
    if in_degree[i] == 0:
        heapq.heappush(queue, i)

while queue:
    vertex = heapq.heappop(queue)
    print(vertex, end=' ')
    for next_ in graph[vertex]:
        in_degree[next_] -= 1
        if in_degree[next_] == 0:
            heapq.heappush(queue, next_)