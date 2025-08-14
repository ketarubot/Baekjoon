#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 26

int main(void) {
    int n;
    scanf("%d", &n);

    int **arr = malloc(MAXLEN * sizeof(int *));
    for (int i = 0; i < MAXLEN; i++) {
        arr[i] = malloc(MAXLEN * sizeof(int));
        for (int j = 0; j < MAXLEN; j++) {
            arr[i][j] = 0;
        }
    }

    for (int _ = 0; _ < n; _++) {
        char a, b;
        scanf("%*c%c is %c", &a, &b);
        arr[a - 'a'][b - 'a'] = 1;
    }

    for (int k = 0; k < MAXLEN; k++) {
        for (int i = 0; i < MAXLEN; i++) {
            for (int j = 0; j < MAXLEN; j++) {
                if (arr[i][j]) continue;
                if (arr[i][k] && arr[k][j]) arr[i][j] = 1;
                else arr[i][j] = 0;
            }
        }
    }

    int m;
    scanf("%d", &m);
    for (int _ = 0; _ < m; _++) {
        char a, b;
        scanf("%*c%c is %c", &a, &b);
        printf(arr[a-'a'][b-'a']?"T\n":"F\n");
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}