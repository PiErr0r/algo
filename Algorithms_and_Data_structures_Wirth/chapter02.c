#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helpers.h"
#include "sorting.h"
#define L 50

void simple_sorts() {
  int *a;
  a = (int *)malloc(L * sizeof(int));
  if (a == NULL) {
    printf("Couldn't assign memory!\nExiting...\n");
    exit(1);
  }
  printf("Insertion\n");
  set_arr(a, L);
  disp(a, L);
  insertion_sort(a, L);
  disp(a, L);
  printf("Selection\n");
  set_arr(a, L);
  disp(a, L);
  selection_sort(a, L);
  disp(a, L);
  printf("Bubble\n");
  set_arr(a, L);
  disp(a, L);
  bubble_sort(a, L);
  disp(a, L);
  printf("Shake\n");
  set_arr(a, L);
  disp(a, L);
  shake_sort(a, L);
  disp(a, L);

  free(a);
  return;
}

void advanced_sorts() {
  int *a;
  a = (int *)malloc(L * sizeof(int));
  if (a == NULL) {
    printf("Couldn't assign memory!\nExiting...\n");
    exit(1);
  }

  return;
}

int main() {
  time_t t;
  srand((unsigned) time(&t));
  simple_sorts();
  advanced_sorts();
  return 0;
}
