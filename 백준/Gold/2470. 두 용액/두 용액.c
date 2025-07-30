#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int s = 0, e = n - 1;
    int min_sum = INT_MAX;
    int a = arr[s], b = arr[e];

    while (s < e) {
        int total = arr[s] + arr[e];
        if (abs(total) < abs(min_sum)) {
            min_sum = total;
            a = arr[s];
            b = arr[e];
        }
        if (total < 0)
            s++;
        else
            e--;
    }

    printf("%d %d\n", a, b);
    free(arr);
    return 0;
}