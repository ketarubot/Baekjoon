#include <stdio.h>

long long power(long long a, long long b, long long c) {
    if (b == 0) return 1;
    long long half = power(a, b / 2, c);
    long long result = (half * half) % c;
    if (b % 2 == 1) result = (result * a) % c;
    return result;
}

int main(void) {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld\n", power(a, b, c));
}