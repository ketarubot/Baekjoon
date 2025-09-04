import sys
input = sys.stdin.readline

n, m = map(int, input().split())
parent = [-1] * n

def find(x: int) -> int:
    root = x
    while parent[root] >= 0:
        root = parent[root]
    while x != root:
        parent[x], x = root, parent[x]
    return root

def union(a: int, b: int) -> None:
    a_root = find(a)
    b_root = find(b)
    if a_root == b_root:
        return
    if parent[a_root] <= parent[b_root]:
        parent[a_root] += parent[b_root]
        parent[b_root] = a_root
    else:
        parent[b_root] += parent[a_root]
        parent[a_root] = b_root

i = 0
cycle = False
for i in range(1, m+1):
    a, b = map(int, input().split())
    if find(a) == find(b):
        cycle = True
        break
    union(a, b)
print(i if cycle else 0)