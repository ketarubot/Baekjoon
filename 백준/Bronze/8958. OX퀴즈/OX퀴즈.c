#include <stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int score = 1, total = 0, j = 0;
        char result[81] = " ";
        scanf("%s", result);
        while (result[j] != '\0') {
            if (result[j++] == 'X') {
                score = 1;
            }
            else {
                total += score++;
            }
        }
        printf("%d\n", total);
    }
}