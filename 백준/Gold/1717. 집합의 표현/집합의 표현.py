import sys
input = sys.stdin.readline

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

n, m = map(int, input().split())
parent = [-1] * (n+1)

output = []
for _ in range(m):
    cmd, a, b = map(int, input().split())
    if cmd == 0:
        union(a, b)
    else:
        output.append("yes" if find(a) == find(b) else "no")

print("\n".join(output))