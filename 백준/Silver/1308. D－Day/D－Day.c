#include <stdio.h>

int is_leap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int mdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int days_from_1AD(int y, int m, int d) {
    int days = 0;
    for (int i = 1; i < y; i++) {
        days += is_leap(i) ? 366 : 365;
    }
    for (int i = 1; i < m; i++) {
        days += mdays[i];
        if (i == 2 && is_leap(y)) days += 1;
    }
    days += d;
    return days;
}

int main() {
    int y1, m1, d1;
    int y2, m2, d2;
    scanf("%d %d %d", &y1, &m1, &d1);
    scanf("%d %d %d", &y2, &m2, &d2);

    if (y2 - y1 > 1000 ||
        (y2 - y1 == 1000 && (m2 > m1 || (m2 == m1 && d2 >= d1)))) {
        printf("gg\n");
        return 0;
        }

    int dday = days_from_1AD(y2, m2, d2) - days_from_1AD(y1, m1, d1);
    printf("D-%d\n", dday);
}