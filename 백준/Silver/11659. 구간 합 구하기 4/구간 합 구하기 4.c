#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    int *sum = malloc(sizeof(int) * n);
    sum[0] = arr[0];
    for (int i = 1; i<n; i++) {
        sum[i] = sum[i-1] + arr[i];
    }
    for (int t = 0; t<m; t++) {
        int i, j;
        scanf("%d %d", &i, &j);
        int result = sum[--j];
        if (--i) result -= sum[--i];
        printf("%d\n", result);
    }
    free(arr);
}