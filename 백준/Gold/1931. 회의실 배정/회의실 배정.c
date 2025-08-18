#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    const int *x = *(const int **)a;
    const int *y = *(const int **)b;

    if (x[1] > y[1]) return 1;
    if (x[1] < y[1]) return -1;
    if (x[0] > y[0]) return 1;
    if (x[0] < y[0]) return -1;
    return 0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int **times = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        times[i] = malloc(sizeof(int) * 2);
        scanf("%d %d", &times[i][0], &times[i][1]);
    }

    qsort(times, n, sizeof(int *), compare);

    int current_time = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (times[i][0] >= current_time) {
            current_time = times[i][1];
            count++;
        }
    }
    printf("%d\n", count);

    for (int i = 0; i < n; i++) free(times[i]);
    free(times);
}