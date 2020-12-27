#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

void set_arr(int *a, int l) {
  int i;
  for (i = 0; i < l; ++i) {
    *(a + i) = rand() % 100;
  }
  return;
}

void disp(int *a, int l) {
  int i;
  for (i = 0; i < l; ++i) {
    printf("%4d", *(a + i));
  }
  printf("\n");
  return;
}

