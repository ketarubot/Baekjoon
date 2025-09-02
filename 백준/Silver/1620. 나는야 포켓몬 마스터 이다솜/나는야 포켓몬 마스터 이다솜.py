import sys
input = sys.stdin.readline

n, m = map(int, input().split())

np = [""] * (n+1)
pn = {}
for i in range(1, n+1):
    name = input().strip()
    np[i] = name
    pn[name] = i

output = []
for _ in range(m):
    q = input().strip()
    if q.isalpha():
        output.append(pn[q])
    else:
        output.append(np[int(q)])
print('\n'.join(map(str, output)))