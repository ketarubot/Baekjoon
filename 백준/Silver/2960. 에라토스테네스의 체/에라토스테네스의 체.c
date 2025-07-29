#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    bool *eratos = malloc(n+1);
    for (int i = 0; i <= n; i++) eratos[i] = true;
    int result = 2, count = 1;
    for (int i = 2; i <= n; i++) {
        if (eratos[i]) {
            for (int j = i; j <= n; j+=i) {
                if (eratos[j]) {
                    eratos[j] = false;
                    result = j;
                    if (count++ == k) break;
                }
            }
        }
        if (count > k) break;
    }
    printf("%d", result);
    free(eratos);
}