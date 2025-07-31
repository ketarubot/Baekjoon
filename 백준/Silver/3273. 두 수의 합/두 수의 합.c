#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int main(void) {
    int n, x;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);

    qsort(arr, n, sizeof(int), compare);
    int count = 0;
    int s = 0, e = n-1;

    while (s < e) {
        int sum = arr[s] + arr[e];
        if (sum == x) {
            count++, s++, e--;
        } else if (sum > x) {
            e--;
        } else {
            s++;
        }
    }

    printf("%d", count);

    free(arr);
}
