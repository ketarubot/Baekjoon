#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* string;

int main() {
    int n;
    scanf("%d", &n);

    int m;
    scanf("%d", &m);

    const int p_len = n*2+1;
    string p = malloc(sizeof(char) * (p_len+1));
    for (int i = 0; i < p_len; i++) {
        p[i] = i%2?'O':'I';
    }
    p[p_len] = '\0';

    string s = malloc(sizeof(char) * (m+1));
    scanf("%s", s);

    int p_count = 0;
    for (int i = 0; i < m-p_len+1; i++) {
        string temp = malloc(sizeof(char) * (p_len+1));
        strncpy(temp, s+i, p_len);
        if (strcmp(temp, p) == 0) p_count++;
        free(temp);
    }
    printf("%d\n", p_count);
    free(p);
    free(s);
}