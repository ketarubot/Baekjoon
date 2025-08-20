#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int binary_search(int *arr, int low, int high, int value) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int *pos = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }

    int *sorted_pos = malloc(sizeof(int) * n);
    memcpy(sorted_pos, pos, sizeof(int) * n);
    qsort(sorted_pos, n, sizeof(int), compare);

    int *rank = malloc(sizeof(int) * n);
    int index = 0;
    rank[index++] = sorted_pos[0];
    for (int i = 1; i < n; i++) {
        if (sorted_pos[i] != sorted_pos[i - 1]) {
            rank[index++] = sorted_pos[i];
        }
    }
    free(sorted_pos);

    for (int i = 0; i < n; i++) {
        printf("%d ", binary_search(rank, 0, index-1, pos[i]));
    }
    free(pos);
    free(rank);
}