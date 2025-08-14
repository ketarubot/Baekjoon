#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d%*c", &n);

    int **friend = malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        friend[i] = malloc(n*sizeof(int));
        for (int j = 0; j < n; j++) {
            char is_friend;
            scanf("%c", &is_friend);
            friend[i][j] = is_friend=='Y';
        }
        getchar();
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (friend[i][j]) {
                count++;
                continue;
            }
            for (int k = 0; k < n; k++) {
                if (friend[i][k] && friend[k][j]) {
                    count++;
                    break;
                }
            }
        }
        if (count > max) max = count;
    }
    printf("%d\n", max);

    for (int i = 0; i < n; i++) {
        free(friend[i]);
    }
    free(friend);
}