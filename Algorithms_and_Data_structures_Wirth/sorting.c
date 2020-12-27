#include "helpers.h"

void insertion_sort(int *a, int l) {
  int i, j, x;
  for (i = 1; i < l; ++i) {
    x = *(a + i);
    for (j = i; j > 0 && x < *(a + j - 1); --j) {
      *(a + j) = *(a + j - 1);
    }
    *(a + j) = x;
  }
  return;
}

void selection_sort(int *a, int l) {
  int i, j, k, x;
  for (i = 0; i < l; ++i) {
    k = i; x = a[i];
    for (j = i + 1; j < l; ++j) {
      if (*(a + j) < *(a + k)) {
        k = j; x = a[k];
      } 
    }
    a[k] = a[i]; a[i] = x;
  }
  return;
}

void bubble_sort(int *a, int l) {
  int i, j;
  for (i = 1; i < l; ++i) {
    for (j = l - 1; j >= i; --j) {
      if (*(a + j) < *(a + j - 1)) swap(a+j, a+j-1);
    }
  }
  return;
}

void shake_sort(int *a, int l) {
  int i, j, L = 0, R = l - 1;
  j = R;
  while (L <= R) {
    for (i = R; i >= L; --i) {
      if (*(a + i) < *(a + i - 1)) {
        swap(a+i, a+i-1);
        j = i;
      }
    }
    L = j + 1;
    for (i = L; i <= R; ++i) {
      if (*(a + i) < *(a + i - 1)) {
        swap(a+i, a+i-1);
        j = i;
      }
    }
    R = j - 1;
  }
  return;
}
