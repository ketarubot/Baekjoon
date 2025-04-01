fibo = [0, 1] 
for i in range(1, 20):
    fibo.append(fibo[i-1] + fibo[i])
n = int(input())
print(fibo[n])