#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int *aim = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &aim[i]);
    }
    int *stack = malloc(sizeof(int) * n);
    for (int i = 0; i <= n; i++) stack[i] = false;
    char *result = malloc(n*3);
    int index = 0;
    int top = -1;
    int num = 1;
    bool able = true;
    for (int x = 0; x < n; x++) {
        int target = aim[x];
        while (num <= target) {
            stack[++top] = num++;
            result[index++] = '+';
        }
        if (stack[top] == target) {
            top--;
            result[index++] = '-';
        } else {
            able = false;
            break;
        }
    }
    if (able) {
        for (int i = 0; i < index; i++) {
            printf("%c\n", result[i]);
        }
    } else {
        printf("NO\n");
    }

    free(aim);
    free(stack);
    free(result);
}