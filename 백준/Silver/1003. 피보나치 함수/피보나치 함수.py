t = int(input())
for _ in range(t):
    n = int(input())
    dp = [list()] * max(n+1, 2)
    dp[0] = [1, 0]
    dp[1] = [0, 1]
    for i in range(2, n+1):
        c0 = dp[i-1][0] + dp[i-2][0]
        c1 = dp[i-1][1] + dp[i-2][1]
        dp[i] = [c0, c1]
    print(dp[n][0], dp[n][1])