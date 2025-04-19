import math

def isprime(a):
    if a < 2:
        return False
    for d in range(2, int(math.sqrt(a)) + 1):
        if a % d == 0:
            return False
    return True

m = int(input())
n = int(input())
prime = []

for i in range(m, n+1):
    if isprime(i):
        prime.append(i)

if prime:
    print(sum(prime))
    print(prime[0])
else:
    print(-1)