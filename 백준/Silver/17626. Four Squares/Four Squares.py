import math

def four_squares(n):
    if int(math.isqrt(n))**2 == n:
        return 1

    for i in range(1, int(math.isqrt(n)) + 1):
        if int(math.isqrt(n - i*i))**2 == n - i*i:
            return 2
        
    temp = n
    while temp % 4 == 0:
        temp //= 4
    if temp % 8 == 7:
        return 4

    return 3


n = int(input())
print(four_squares(n))