#include <stdio.h>

int main(void) {
    char ref[5][16] = {" "};
    for (int i = 0; i < 5; i++) {
        scanf("%s", ref[i]);
    }
    int bref[5] = {0};
    char result[76] = " ";
    int count = 0;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 5; j++) {
            if (!bref[j]) {
                if (ref[j][i] == '\0') {
                    bref[j] = 1;
                    continue;
                }
                else {
                    result[count++] = ref[j][i];
                }
            }
        }
    }
    printf("%s\n", result);
}