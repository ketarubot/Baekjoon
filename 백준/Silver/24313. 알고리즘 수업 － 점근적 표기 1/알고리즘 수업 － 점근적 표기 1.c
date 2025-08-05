#include <stdio.h>

typedef _Bool bool;

int main(void) {
    int a1, a0, c, n;
    scanf("%d %d", &a1, &a0);
    scanf("%d", &c);
    scanf("%d", &n);
    bool big_o =
        a1>c ? 0 :
        a1*n+a0 <= c*n;
    printf("%d", big_o);
}