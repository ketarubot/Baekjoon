#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void rearrange(int *src, int len);

int main(void) {
    int t;
    scanf("%d", &t);
    for (int _ = 0; _<t; _++) {
        int n, m;
        scanf("%d %d", &n, &m);
        int *queue = malloc(sizeof(int) * n);
        int *prio = malloc(sizeof(int) * n);
        bool *printed = malloc(sizeof(bool) * n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &prio[i]);
            queue[i] = i;
            printed[i] = false;
        }
        char count = 1;
        while (1) {
            int current = queue[0];
            if (printed[current]) {
                rearrange(queue, n);
                continue;
            }
            bool isMax = true;
            for (int i = 0; i < n; i++) {
                if (!printed[i]) {
                    if (prio[i] > prio[current]) {
                        rearrange(queue, n);
                        isMax = false;
                        break;
                    }
                }
            }
            if (isMax) {
                printed[current] = true;
                if (current == m) {
                    printf("%d\n", count);
                    break;
                }
                count++;
            }
        }
        free(queue);
        free(prio);
        free(printed);
    }
}

void rearrange(int *src, int len) {
    int temp = src[0];
    for (int i = 0; i < len-1; i++) {
        src[i] = src[i+1];
    }
    src[len-1] = temp;
}