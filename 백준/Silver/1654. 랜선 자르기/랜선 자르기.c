#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);

    int *lans = malloc(sizeof(int) * k);
    int max_length = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d", &lans[i]);
        if (lans[i] > max_length) 
            max_length = lans[i];
    }

    long long left = 1, right = max_length, ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long count = 0;

        for (int i = 0; i < k; i++) {
            count += lans[i] / mid;
        }

        if (count >= n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%lld\n", ans);
    free(lans);
}