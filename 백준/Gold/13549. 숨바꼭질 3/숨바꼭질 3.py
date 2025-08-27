from collections import deque as dq
from sys import stdin
f_input = stdin.readline

MAX_POS = 100000

n, k = map(int, f_input().split())

min_cost = [float('inf')] * (MAX_POS + 1)
min_cost[n] = 0

queue = dq([n])
while queue:
    node = queue.popleft()
    cur = min_cost[node]
    if node-1 >= 0 and cur+1 < min_cost[node-1]:
        min_cost[node-1] = cur+1
        queue.append(node-1)
    if node+1 <= MAX_POS and cur+1 < min_cost[node+1]:
        min_cost[node+1] = cur+1
        queue.append(node+1)
    if node*2 <= MAX_POS and cur < min_cost[node*2]:
        min_cost[node*2] = cur
        queue.appendleft(node*2)
print(min_cost[k])