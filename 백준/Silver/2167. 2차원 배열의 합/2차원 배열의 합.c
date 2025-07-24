#include <stdio.h>

short matrix[300][300];
int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int k;
    scanf("%d", &k);
    for (int t = 0; t<k; t++) {
        int si, sj, x, y;
        scanf("%d %d %d %d", &si, &sj, &x, &y);
        si--, sj--, x--, y--;
        int result = 0;
        for (int i = si; i<=x; i++) {
            for (int j = sj; j<=y; j++) {
                result += matrix[i][j];
            }
        }
        printf("%d\n", result);
    }
}