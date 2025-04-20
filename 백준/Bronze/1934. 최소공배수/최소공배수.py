from sys import stdin
input = stdin.readline

def gcd(a, b):
    if b == 0:
        return a
    a, b = b, a % b
    return gcd(a, b)

def lcm(a, b):
    return a * b // gcd(a, b)

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    print(lcm(a, b))