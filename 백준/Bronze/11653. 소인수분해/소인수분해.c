#include <stdio.h>
#include <math.h>

int main(void){
    int n;
    scanf("%d", &n);
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++){
        while (n % i == 0){
            printf("%d\n", i);
            n /= i;
        }
    }
    if (n >= 2)
        printf("%d\n", n);
    return 0;
}