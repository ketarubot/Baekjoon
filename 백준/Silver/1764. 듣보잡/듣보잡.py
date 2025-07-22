n, m = map(int, input().split())
h = {input() for _ in range(n)}
s = {input() for _ in range(m)}
r = []
if n>=m:
    for p in h:
        if p in s:
            r.append(p)
else:
    for p in s:
        if p in h:
            r.append(p)
print(len(r))
for hs in sorted(r):
    print(hs)