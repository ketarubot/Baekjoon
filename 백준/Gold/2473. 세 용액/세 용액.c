#include <stdio.h>
#include <stdlib.h>

#define MAX 9223372036854775807
#define lint long long

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void print_arr(const int *arr, const int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    lint min_at = MAX;
    int combi[3] = {0};
    for (int i = 0; i < n-2; i++) {
        int s = i+1;
        int e = n-1;
        while (s < e) {
            const lint total = (lint)arr[i] + (lint)arr[s] + (lint)arr[e];
            const lint at = llabs(total);
            if (min_at > at) {
                min_at = at;
                combi[0] = arr[i];
                combi[1] = arr[s];
                combi[2] = arr[e];
            }
            if (total > 0) e--;
            else s++;
        }
    }
    print_arr(combi, 3);
    free(arr);
}