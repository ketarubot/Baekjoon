#include <stdio.h>
#include <stdlib.h>

int result = -1;
int k, count = 0;

void merge_sort(int *arr, int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    int *tmp = malloc(sizeof(int) * (end - start + 1));
    int i = start, j = mid + 1, t = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            tmp[t++] = arr[i++];
        else
            tmp[t++] = arr[j++];
    }
    while (i <= mid) tmp[t++] = arr[i++];
    while (j <= end) tmp[t++] = arr[j++];

    for (int i = start, t_idx = 0; i <= end; i++, t_idx++) {
        arr[i] = tmp[t_idx];
        count++;
        if (count == k) result = arr[i];
    }

    free(tmp);
}

int main(void) {
    int n;
    scanf("%d %d", &n, &k);
    int *A = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    merge_sort(A, 0, n - 1);
    printf("%d\n", result);
    free(A);
}