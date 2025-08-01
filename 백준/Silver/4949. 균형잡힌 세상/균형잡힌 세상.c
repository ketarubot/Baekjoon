#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef _Bool bool;
#define true 1
#define false 0

void push(char *stack, int *top, char ch);
bool judge(char *stack, int *top, char ch);

int main(void) {
    while (1) {
        char str[101];
        scanf("%[^\n]", str);
        getchar();
        if (str[0] == '.') break;
        bool isBalanced = true;
        int len = strlen(str);
        char *stack = malloc(len);
        int top = -1;
        for (int i = 0; i < len-1; i++) {
            if (str[i] == '(' || str[i] == '[') {
                push(stack, &top, str[i]);
            } else if (str[i] == ')' || str[i] == ']') {
                isBalanced = judge(stack, &top, str[i]);
                if (!isBalanced) break;
            }
        }
        if (top >= 0) isBalanced = false;
        printf(isBalanced?"yes\n":"no\n");

        free(stack);
    }
}

void push(char *stack, int *top, char ch) {
    stack[++(*top)] = ch;
}

bool judge(char *stack, int *top, char ch) {
    if (*top < 0) return false;
    if (ch == ')' && stack[*top] != '(') return false;
    if (ch == ']' && stack[*top] != '[') return false;
    stack[(*top)--] = 0;
    return true;
}