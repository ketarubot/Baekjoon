from sys import stdin
input = stdin.readline

n, m = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]
m, k = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(m)]
result = [[0 for _ in range(k)] for i in range(n)]
for i in range(n):
    for j in range(k):
        for idx in range(m):
            result[i][j] += A[i][idx]*B[idx][j]
for i in range(n):
    for j in range(k):
        print(result[i][j], end=' ')
    print()