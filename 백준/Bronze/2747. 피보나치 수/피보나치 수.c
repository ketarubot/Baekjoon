#include <stdio.h>

int fibo(int n) {
    if (n <= 1) return n;

    int a = 0, b = 1, temp = 0;
    for (int i = 1; i < n; i++) {
        temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", fibo(n));
}