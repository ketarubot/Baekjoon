n = int(input())
dp = [float('inf')] * (n+1)

dp[n] = 0
for i in range(n, 1, -1):
    comp = dp[i] + 1
    if i%3 == 0 and dp[i//3] > comp:
        dp[i//3] = comp
    if i%2 == 0 and dp[i//2] > comp:
        dp[i//2] = comp
    if dp[i-1] > comp:
        dp[i-1] = comp
print(dp[1])