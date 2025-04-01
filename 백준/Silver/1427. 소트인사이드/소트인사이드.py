n = int(input())
a = [int(_) for _ in str(n)]
a.sort()
a.reverse()
for i in a:
    print(i, end='')