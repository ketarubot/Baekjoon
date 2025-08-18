#include <stdio.h>
#include <stdlib.h>

#define MAX 2147483647

int main(void) {
    int v, e;
    scanf("%d %d", &v, &e);

    int **cost = malloc(sizeof(int *) * v);
    for (int i = 0; i < v; i++) {
        cost[i] = malloc(sizeof(int) * v);
        for (int j = 0; j < v; j++) {
            cost[i][j] = MAX;
        }
    }

    for (int t = 0; t < e; t++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--, b--;
        cost[a][b] = c<cost[a][b]?c:cost[a][b];
    }

    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (cost[i][k] != MAX && cost[k][j] != MAX) {
                    if (cost[i][j] > cost[i][k] + cost[k][j]) {
                        cost[i][j] = cost[i][k] + cost[k][j];
                    }
                }
            }
        }
    }

    int min_cycle = MAX;
    for (int i = 0; i < v; i++) {
        if (cost[i][i] < min_cycle) {
            min_cycle = cost[i][i];
        }
        free(cost[i]);
    }
    free(cost);
    printf("%d\n", min_cycle==MAX?-1:min_cycle);
}