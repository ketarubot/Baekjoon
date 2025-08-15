#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int guests;
    scanf("%d", &guests);

    int **friend = malloc(sizeof(int *) * guests);
    for (int i = 0; i < guests; i++) {
        friend[i] = malloc(sizeof(int) * guests);
        for (int j = 0; j < guests; j++) {
            if (i == j) friend[i][j] = 0;
            else friend[i][j] = 10000;
        }
    }

    while (1) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == -1 && b == -1) break;
        a--, b--;
        friend[a][b] = friend[b][a] = 1;
    }

    for (int k = 0; k < guests; k++) {
        for (int i = 0; i < guests; i++) {
            for (int j = 0; j < guests; j++) {
                if (i == j) continue;
                const int cross = friend[i][k] + friend[k][j];
                if (cross < friend[i][j]) friend[i][j] = cross;
            }
        }
    }

    int *score = malloc(sizeof(int) * guests);
    int min = 10000;
    for (int i = 0; i < guests; i++) {
        score[i] = 0;
        for (int j = 0; j < guests; j++) {
            if (friend[i][j] > score[i]) {
                score[i] = friend[i][j];
            }
        }
        if (min > score[i]) min = score[i];
    }
    for (int i = 0; i < guests; i++) {
        free(friend[i]);
    }
    free(friend);

    int *candidates = malloc(sizeof(int) * guests);
    int index = 0;
    for (int i = 0; i < guests; i++) {
        if (score[i] == min) {
            candidates[index++] = i+1;
        }
    }
    free(score);

    printf("%d %d\n", min, index);
    for (int i = 0 ; i < index; i++) {
        printf("%d ", candidates[i]);
    }
    free(candidates);
}