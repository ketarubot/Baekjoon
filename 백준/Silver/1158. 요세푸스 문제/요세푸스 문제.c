#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    int *queue = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) queue[i] = i + 1;

    int size = n;
    int index = 0;

    printf("<");
    while (size > 0) {
        index = (index + k - 1) % size;
        printf("%d", queue[index]);

        for (int i = index; i < size - 1; i++) {
            queue[i] = queue[i + 1];
        }

        size--;

        if (size > 0) printf(", ");
    }
    printf(">\n");

    free(queue);
}