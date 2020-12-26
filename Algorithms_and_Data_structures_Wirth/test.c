#include <stdio.h>
#include <stdlib.h>

 int n_pow(int a, int b) {
   // return a ^ b
   int y = 1;
   while (b > 0) {
     if (b & 1) y *= a;
     a *= a;
     b >>= 1;
  }
  return y;
}

int kmr_search(char *s, int n, char *p, int m) {

  int i = 0, j = 0, k = 0, *d = NULL;
  d = (int *) malloc(m * sizeof(int));
  if (d == NULL)
    exit(0);

  while (j < m - 1) {
    while (k >= 0 && *(p + j) != *(p + k)) k = *(d + k);
    k++; j++;
    *(d + j) = *(p + j) == *(p + k) ? *(d + k) : k;
  }

  while (i < n && j < m) {
    while (j >= 0 && *(s + i) != *(p + j)) j = *(d + j);
    i++; j++;
  }

  return j == m ? i - m : -1;
}

int bm_search(char *s, int n, char *p, int m) {
  int i = 0, j = 0, k = 0;
  int d[128];
  for (i = 0; i < 128; d[i] = m, ++i);
  for (j = 0; j < m - 2; d[ *(p + j) ] = m - j - 1, ++j);
  i = m;
  do {
    j = m; k = i;
    while (j >= 0 && *(p + j--) == *(s + k--));
    i += d[*(s + i - 1)];
  } while (j >= 0 && i <= n);
}



int main() {


  printf("%d ^ %d = %d\n", 3, 11, n_pow(3, 11));
  printf("%d ^ %d = %d\n", 2, 10, n_pow(2, 10));
  printf("%d ^ %d = %d\n", 123, 11, n_pow(123, 11));
  return 0;
}

