import math

def isprime(x):
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return
    print(x)

m, n = map(int, input().split())

for i in range(m, n+1):
    if i != 1:
        isprime(i)