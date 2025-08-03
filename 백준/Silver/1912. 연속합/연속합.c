#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);
    int *dp = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = dp[0] = arr[0];
    for (int i = 1; i < n; i++) {
        int temp = dp[i-1]+arr[i];
        dp[i] = arr[i]>temp?arr[i]:temp;
        if (dp[i] > max) max = dp[i];
    }
    printf("%d", max);

    free(arr);
    free(dp);
}