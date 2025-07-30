#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push_front(int *deque, int num, int *top) {
    for (int i = ++*top; i > 0; i--) {
        deque[i] = deque[i-1];
    }
    deque[0] = num;
}

void front(int *deque, int *top) {
    for (int i = 0; i < *top; i++) {
        deque[i] = deque[i+1];
    }
    deque[(*top)--] = -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *deque = malloc(sizeof(int) * n);
    int top = -1;
    for (int i = 0; i < n; i++) deque[i] = -1;
    for (int i = 0; i < n; i++) {
        char cmd[11];
        scanf("%s", cmd);
        if (strcmp(cmd, "push_front") == 0) {
            int num;
            scanf("%d", &num);
            push_front(deque, num, &top);
        } else if (strcmp(cmd, "push_back") == 0) {
            int num;
            scanf("%d", &num);
            deque[++top] = num;
        } else if (strcmp(cmd, "pop_front") == 0) {
            if (top <= -1) {
                printf("-1\n");
            } else {
                printf("%d\n", deque[0]);
                front(deque, &top);
            }
        } else if (strcmp(cmd, "pop_back") == 0) {
            if (top <= -1) {
                printf("-1\n");
            } else {
                printf("%d\n", deque[top]);
                deque[top--] = -1;
            }
        } else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", top+1);
        } else if (strcmp(cmd, "front") == 0) {
            printf("%d\n", deque[0]);
        } else if (strcmp(cmd, "back") == 0) {
            if (top <= -1) {
                printf("-1\n");
            } else {
                printf("%d\n", deque[top]);
            }
        } else {
            printf("%d\n", top>=0?0:1);
        }
    }

    free(deque);
}