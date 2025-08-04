#include <stdio.h>
#include <stdlib.h>

int k = 0;
int **result = NULL;

void add_result(int a, int b) {
    result = realloc(result, sizeof(int *) * (k+1));
    result[k] = malloc(sizeof(int) * 2);
    result[k][0] = a;
    result[k][1] = b;
    k++;
}

void hanoi(int n, int from_pos, int to_pos, int aux_pos) {
    if (n == 1) {
        add_result(from_pos, to_pos);
        return;
    }
    hanoi(n-1, from_pos, aux_pos, to_pos);
    add_result(from_pos, to_pos);
    hanoi(n-1, aux_pos, to_pos, from_pos);
}

int main(void) {
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 3, 2);
    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d %d\n", result[i][0], result[i][1]);
    }
    for (int i = 0; i < k; i++) free(result[i]);
    free(result);
}