from collections import deque
import sys

A, B = map(int, input().split())

queue = deque([(A, 1)])
while queue:
    node, count = queue.popleft()
    if node == B:
        print(count)
        sys.exit(0)
    if node*2 <= B:
        queue.append((node*2, count+1))
    if int(f'{node}1') <= B:
        queue.append((int(f'{node}1'), count+1))
print(-1)