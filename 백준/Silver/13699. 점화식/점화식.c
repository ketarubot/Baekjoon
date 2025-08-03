#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long int_ul;

int main(void) {
    int n;
    scanf("%d", &n);

    int_ul *arr = malloc(sizeof(int_ul) * (n+1));
    arr[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            arr[i] += arr[j] * arr[i-j-1];
        }
    }
    printf("%llu\n", arr[n]);

    free(arr);
}