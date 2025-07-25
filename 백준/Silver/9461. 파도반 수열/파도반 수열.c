#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        int n;
        scanf("%d", &n);
        long long *dp = malloc(sizeof(long long) * (n+1>3?n+1:3));
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-2] + dp[i-3];
        }
        printf("%lld\n", dp[n]);

        free(dp);
    }
}