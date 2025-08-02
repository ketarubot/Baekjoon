#include <stdio.h>
#include <stdlib.h>

int recur_count = 0;
int dp_count = 0;

int fib(int n) {
    if (n <= 2) {
        recur_count++;
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int fibonacci(int n) {
    int *f = (int *) malloc(sizeof(int) * (n+1));
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
        dp_count++;
    }
    int result = f[n];
    free(f);
    return result;
}

int main(void) {
    int n;
    scanf("%d", &n);
    fib(n);
    fibonacci(n);
    printf("%d %d", recur_count, dp_count);
}