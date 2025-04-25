#include <stdio.h>

int field[100][100];
int main(void) {
    int n;
    scanf("%d", &n);
    for (int r = 0; r < n; r++) {
        int x, y;
        scanf("%d %d", &x, &y);
        int sy = 100 - ++y, sx = x;
        for (int i = sy; i > sy - 10; i--) {
            for (int j = sx; j < sx + 10; j++) {
                field[i][j] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (field[i][j]) count++;
        }
    }
    printf("%d\n", count);
}
