from sys import stdin
input = stdin.readline

def divs_n(n: int):
    divs = []
    for i in range(1, n//2+1):
        if n % i == 0:
            divs.append(i)
    return divs

while True:
    n = int(input())
    if n == -1: break
    divs = divs_n(n)
    if n == sum(divs):
        print(n, '= '+' + '.join(map(str, divs)))
    else:
        print(n, 'is NOT perfect.')
