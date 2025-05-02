#include <stdio.h>

void spira(int n){
  for (int i = 1; i <= n; i++) {
    for (int j = i; j < n; j++) {
      printf(" ");
    }
    for (int j = 1; j <= ((i - 1) * 2 + 1); j++) {
      printf("*");
    }
    printf("\n");
  }
}

int main(void) {
  int n = 0;
  scanf("%d", &n);
  spira(n);

  return 0;
}