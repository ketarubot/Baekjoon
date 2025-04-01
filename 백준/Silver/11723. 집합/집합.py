from sys import stdin
input = stdin.readline

m = int(input())
s = set()
for i in range(m):
    cmd = tuple(input().split())
    if len(cmd) >= 2:
        x = int(cmd[1])
    if 'add' in cmd:
        if not x in s:
            s.add(x)
    elif 'check' in cmd:
        print(int(x in s))
    elif 'remove' in cmd:
        if x in s:
            s.remove(x)
    elif 'toggle' in cmd:
        if x in s:
            s.remove(x)
        else:
            s.add(x)
    elif 'all' in cmd:
        s = set(range(1,21))
    elif 'empty' in cmd:
        s.clear()