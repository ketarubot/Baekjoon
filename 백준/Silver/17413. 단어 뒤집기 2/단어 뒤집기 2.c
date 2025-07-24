#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void reverse_word(char *s, int *start, int end);

int main(void) {
    char *str = malloc(100001);
    scanf("%[^\n]", str);
    bool inTag = false;
    int len = strlen(str);
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (inTag) {
            if (str[i] == '>') {
                inTag = false;
                start = i+1;
            }
        } else {
            if (str[i] == '<') {
                inTag = true;
                reverse_word(str, &start, i-1);
            }
            else if (str[i] == ' ' || i == len) {
                reverse_word(str, &start, i-1);
            }
        }
    }
    printf("%s\n", str);

    free(str);
}

void reverse_word(char *str, int *start, int end) {
    if (*start > end) return;
    for (int i = 0; i <= (end-*start)/2; i++) {
        char temp = str[*start+i];
        str[*start+i] = str[end-i];
        str[end-i] = temp;
    }
    *start = end+2;
}