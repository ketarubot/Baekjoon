#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int* rope = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &rope[i]);
    }
    qsort(rope, n, sizeof(int), compare);

    int max_weight = 0;
    for (int i = 0; i < n; i++) {
        if (rope[i] * (n - i) > max_weight) {
            max_weight = rope[i] * (n - i);
        }
    }
    printf("%d\n", max_weight);
}