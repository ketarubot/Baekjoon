#include <stdio.h>
#include <stdlib.h>

#define MAX_C 1000000000LL
typedef long long ll;

int main(void) {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    ll **cost = malloc(sizeof(ll *) * n);
    for (int i = 0; i < n; i++) {
        cost[i] = malloc(sizeof(ll) * n);
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cost[i][j] = 0;
                continue;
            }
            cost[i][j] = MAX_C;
        }
    }

    for (int t = 0; t < m; t++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--, b--;
        cost[a][b] = cost[a][b]>c?c:cost[a][b];
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                ll cross = cost[i][k] + cost[k][j];
                if (cost[i][k] != MAX_C && cost[k][j] != MAX_C) {
                    if (cross < cost[i][j]) {
                        cost[i][j] = cross;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lld ", cost[i][j]==MAX_C?0:cost[i][j]);
        }
        free(cost[i]);
        printf("\n");
    }
    free(cost);
}