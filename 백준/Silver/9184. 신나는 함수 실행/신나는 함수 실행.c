#include <stdio.h>

int w_arr[21][21][21];

void fill_w() {
    for (int a = 0; a <= 20; a++) {
        for (int b = 0; b <= 20; b++) {
            for (int c = 0; c <= 20; c++) {
                if (a == 0 || b == 0 || c == 0) {
                    w_arr[a][b][c] = 1;
                } else if (a < b && b < c) {
                    w_arr[a][b][c] = w_arr[a][b][c-1]
                                   + w_arr[a][b-1][c-1]
                                   - w_arr[a][b-1][c];
                } else {
                    w_arr[a][b][c] = w_arr[a-1][b][c]
                                   + w_arr[a-1][b-1][c]
                                   + w_arr[a-1][b][c-1]
                                   - w_arr[a-1][b-1][c-1];
                }
            }
        }
    }
}

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w_arr[20][20][20];
    return w_arr[a][b][c];
}

int main(void) {
    fill_w();

    while (1) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
}