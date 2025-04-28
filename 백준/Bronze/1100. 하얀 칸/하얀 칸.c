#include <stdio.h>

char chess[8][9];
int main(void) {
    for (int i = 0; i < 8; i++) {
        scanf("%s", &chess[i]);
    }
    int white = 1, count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (white && chess[i][j] == 'F') count++;
            white = !white;
        }
        white = !white;
    }
    printf("%d\n", count);
}
