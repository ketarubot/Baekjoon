#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int m;
    scanf("%d", &m);

    char* s = malloc(sizeof(char) * (m+1));
    scanf("%s", s);

    int count = 0;

    int i = 0;
    while (i < m - 1) {
        int cnt = 0;
        while (i < m - 2 && s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I') {
            cnt++;
            i += 2;
        }
        if (cnt >= n) {
            count += cnt - n + 1;
        }
        i++;
    }
    printf("%d\n", count);
    free(s);
}