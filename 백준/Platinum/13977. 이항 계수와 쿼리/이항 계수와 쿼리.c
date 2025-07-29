#include <stdio.h>
#include <stdlib.h>

void set_dp(int end);
int fact(int x);
int mod_pow(int base, int exp, int mod);
int combi(int n, int k);

int max_dp = 10;
int *dp;
const int MOD = 1000000007;

int main(void) {
    dp = malloc(sizeof(int) * (max_dp+1));
    dp[0] = dp[1] = 1;
    set_dp(max_dp);
    int m;
    scanf("%d", &m);
    for (int r = 0; r < m; r++) {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("%d\n", combi(n, k));
    }
    free(dp);
}

void set_dp(int end) {
    for (int i = 2; i <= end; i++) {
        dp[i] = ((long long)dp[i-1] * i) % MOD;
    }
    max_dp = end;
}

int fact(int x) {
    if (x>max_dp) {
        dp = realloc(dp, sizeof(int) * (x+1));
        set_dp(x);
    }
    return dp[x];
}

// 모듈러 역원 계산 (페르마의 소정리 기반)
int mod_pow(int base, int exp, int mod) {
    long long result = 1;
    long long b = base;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * b) % mod;
        b = (b * b) % mod;
        exp /= 2;
    }
    return (int)result;
}

int combi(int n, int k) {
    int fn = fact(n);
    int fk = fact(k);
    int fnk = fact(n - k);

    long long denom = ((long long)fk * fnk) % MOD;
    long long inv = mod_pow(denom, MOD - 2, MOD); // 역원 계산
    return (int)((fn * inv) % MOD);
}