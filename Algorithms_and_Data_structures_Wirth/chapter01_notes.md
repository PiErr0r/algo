# Chapter 1 - Fundamental data structures


> TODO: tree data structure to act as a Set data structure

Nothing new actually, already know what and how those work (int, float, bool, char, array, struct) but Set is new (new as in not existent in C but it could be built with trees - TODO for later)
But some thing should be noted, like algo to calculate fast power, or one to write negative powers of 2 which i don't exactly understand

```c
int exp(int a, int b) {
  // return a ^ b
  int y = 1;
  while (b > 0) {
    if (b & 1) y *= a;
    a *= a;
    b >>= 1;
  }
  return y;
}
```

We shouldn't forgot the internet stuff about structs:

```c
typedef struct {
  int re, im;
} C__INT;
```

definition of struct for definition of complex numbers. A function can then take an input argument of that type:

```c
C_INT add(C_int *a, C_INT *b) {
  C_INT res;
  res.re = a->re + b->re;
  res.im = a->im + b->im;
  return res;
}
```

The structs can hold function pointers but we shall leave that obscurity for some merrier times.

One other thing very curious is the size of the struct.Iimagine this for a second:

```c
struct a{
  int i;
  double d;
  char c;
}
```

The size of this struct is 24 bytes because integer (4 bytes) and char (1 byte) pad the double (8 bytes) but this struct:

```c
struct b{
  double d;
  int i;
  char c;
}
```

takes only 16 bytes because there is no necessary padding of integer for the double because they all fit the "parent" data type. But all that said it has to pad the next value so int and char will place themselves in 8 bytes allocated for the double.

Curiously this struct:

```c
struct c{
  double d;
  int i;
  char c1, c2, c3, c4;
}
```

requires the same amount of memory.

Interesting thing in binary search is to check the equality of current element with one we wish to find (x) after comparing if it is less or more than x
it should increase the efficiency since this will occur mostly once

## Knuth-Morris-Pratt string search
```c
int kmr_search(char *s, int n, char *p, int m) {

  int i = 0, j = 0, k = 0, *d = NULL;
  d = (int *) malloc(m * sizeof(int));
  if (d == NULL)
    exit(0);

  while (j < m - 1) {
    while (k >= 0 && p[j] != p[k]) k = d[k];
    k++; j++;
    d[j] = p[j] == p[k] ? d[k] : k;
  }

  while (i < n && j < m) {
    while (j >= 0 && s[i] != p[j]) j = d[j];
    i++; j++;
  }

  return j == m ? i - m : -1;
}
```
## Boyer-Moore string search
```c
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
```




