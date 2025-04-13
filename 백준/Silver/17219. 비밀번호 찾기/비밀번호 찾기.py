from sys import stdin #표준 입력
input = stdin.readline

n, m = map(int, input().split())
pws = dict()
for _ in range(n):
    site, pw = input().strip().split()
    pws[site] = pw
for _ in range(m):
    site = input().strip()
    print(pws[site])