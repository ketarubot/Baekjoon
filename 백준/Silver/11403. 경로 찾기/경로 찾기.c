#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int **cost = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        cost[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j]) cost[i][j] = 1;
                else if (cost[i][k] && cost[k][j]) cost[i][j] = 1;
                else cost[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
}