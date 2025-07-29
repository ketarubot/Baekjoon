#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

long long lcm(int a, int b) {
    return (long long) a / gcd(a, b) * b;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (n-- > 0) {
        int a, b, temp;
        scanf("%d %d", &a, &b);
        temp = a;
        a = a>b?a:b;
        b = temp>b?b:temp;
        printf("%lld\n", lcm(a, b));
    }
}