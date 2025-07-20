def isOneNumber(x):
    xs = str(x)
    diff = int(xs[0]) - int(xs[1])
    for j in range(1, len(xs)-1):
        if int(xs[j]) - int(xs[j+1]) != diff:
            return False
    return True

n = int(input())
if n < 100:
    print(n)
else:
    count = 99
    for i in range(100, n+1):
        if isOneNumber(i):
            count+=1
    print(count)
