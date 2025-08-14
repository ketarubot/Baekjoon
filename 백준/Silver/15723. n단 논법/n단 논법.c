#include <stdio.h>

#define MAXLEN 26

int matrix[MAXLEN][MAXLEN];
int main(void) {
    int n;
    scanf("%d", &n);
    
    for (int _ = 0; _ < n; _++) {
        char a, b;
        scanf("%*c%c is %c", &a, &b);
        matrix[a - 'a'][b - 'a'] = 1;
    }

    for (int k = 0; k < MAXLEN; k++) {
        for (int i = 0; i < MAXLEN; i++) {
            for (int j = 0; j < MAXLEN; j++) {
                if (matrix[i][j]) continue;
                if (matrix[i][k] && matrix[k][j]) matrix[i][j] = 1;
                else matrix[i][j] = 0;
            }
        }
    }

    int m;
    scanf("%d", &m);
    for (int _ = 0; _ < m; _++) {
        char a, b;
        scanf("%*c%c is %c", &a, &b);
        printf(matrix[a-'a'][b-'a']?"T\n":"F\n");
    }
}