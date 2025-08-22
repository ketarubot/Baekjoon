from collections import deque
from sys import stdin

f_input = stdin.readline

for _ in range(int(f_input())):
    n, k = map(int, f_input().split())
    graph = {i: [] for i in range(1, n + 1)}
    in_degree = [0] * (n + 1)

    const_time = [0] + list(map(int, f_input().split()))

    dp = [0] * (n + 1)

    for i in range(k):
        x, y = map(int, f_input().split())
        graph[x].append(y)
        in_degree[y] += 1

    queue = deque([])
    for i in range(1, n + 1):
        if in_degree[i] == 0:
            queue.append(i)
            dp[i] = const_time[i]

    w = int(f_input())
    while queue:
        vertex = queue.popleft()
        for next_ in graph[vertex]:
            in_degree[next_] -= 1
            dp[next_] = max(dp[next_], dp[vertex] + const_time[next_])
            if in_degree[next_] == 0:
                queue.append(next_)

    print(dp[w])