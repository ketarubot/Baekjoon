from sys import stdin
input = stdin.readline

n = int(input())
files = []
for _ in range(n):
    files.append(input().strip())
result = list(files[0])
for idx in range(1, n):
    for pos, ch in enumerate(files[idx]):
        if result[pos] != ch:
            result[pos] = '?'
print(''.join(map(str,result)))