#include <stdio.h>
#include <string.h>

int main(void) {
    char s[100001];
    int n;
    scanf("%s %d", s, &n);
    int len = strlen(s);
    for (int b = 0; b < n; b++) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) {
            char f, t;
            scanf(" %c %c", &f, &t);
            for (int i = 0; i < len; i++) {
                if (s[i] == f) s[i] = t;
            }
        } else {
            printf("%s\n", s);
        }
    }
}