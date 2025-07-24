#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(a, b) {char* temp = a; a = b; b = temp;}

void quick_sort(char **arr, int start, int end);
_Bool isSmall(char *src, char *pivot);

int main(void) {
    int n;
    scanf("%d", &n);
    char **guitars = malloc(n*sizeof(char*));
    for (int i = 0; i<n; i++) {
        guitars[i] = malloc(51);
        scanf(" %s", guitars[i]);
    }
    quick_sort(guitars, 0, n-1);
    for (int i = 0; i<n; i++) {
        printf("%s\n", guitars[i]);
    }
}

void quick_sort(char **arr, const int start, const int end) {
    if (end - start <= 0) return;
    char *pivot = arr[end];
    int i = start;
    for (int j = start; j < end; j++) {
        if (isSmall(arr[j], pivot)) {
            SWAP(arr[i], arr[j]);
            i++;
        }
    }
    SWAP(arr[i], arr[end]);
    quick_sort(arr, start, i - 1);
    quick_sort(arr, i + 1, end);
}

_Bool isSmall(char *src, char *pivot) {
    int srclen = strlen(src);
    int pivotlen = strlen(pivot);
    if (srclen != pivotlen) {
        return srclen<pivotlen?1:0;
    }

    int srcsum = 0;
    int pivotsum = 0;
    for (int i = 0; i < srclen; i++) {
        if ('0' <= src[i] && src[i] <= '9') {
            srcsum += src[i] - '0';
        }
        if ('0' <= pivot[i] && pivot[i] <= '9') {
            pivotsum += pivot[i] - '0';
        }
    }
    if (srcsum != pivotsum) {
        return srcsum<pivotsum?1:0;
    }

    for (int i = 0; i < srclen; i++) {
        if (src[i] < pivot[i]) return 1;
        else if (src[i] > pivot[i]) return 0;
    }
    return 0;
}
