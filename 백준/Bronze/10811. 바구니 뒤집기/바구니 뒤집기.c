#include <stdio.h>
#define SWAP(a, b) { int temp = a; a = b; b = temp; }

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int basket[100], count = 1;
    for (int i = 0; i < n; i++) {
        basket[i] = count++;
    }
    for (int i = 0; i < m; i++) {
        int from_pos, to_pos;
        scanf("%d %d", &from_pos, &to_pos);
        for (int j = 0; j < (to_pos - from_pos + 1) / 2; j++) {
            SWAP(basket[from_pos - 1 + j], basket[to_pos - 1 - j]);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", basket[i]);
    }
}