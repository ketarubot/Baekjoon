def fact(n):
    if n <= 1: return 1
    return n * fact(n-1)

def combi(n, r):
    return fact(n)//(fact(n-r)*fact(r))

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    print(combi(m, n))