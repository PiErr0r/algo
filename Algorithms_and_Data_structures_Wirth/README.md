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




# Chapter 2 - Sorting

> TODO:
> Go over sequence sorting once again for better comprehension

use `cc chapter02.c helpers.c sorting.c` to compile chapter02 code

## Simple sorts
- Insertion sort - when found item which is smaller than previous go down the list and insert it in the place where it isn't smaller than the previous item
- Binary insertion sort - intuitively it reduces the number of comparisons but upon closer inspection it is found out to be less efficient than its first implementation, and the number of swaps remains the same
- Selection sort - find a smallest number in the remaining array and replace it with the currently inspected one if it is (j goes from 1 to n, then from 2 to n, ...);
- Bubble sort - swap values if `a > b` and `a_i < b_i`
- Shake sort - imroved bubble sort to gor forward to backwards and backwards to forwards so you improve the assymetry of normal bubble sort which will sort the array fast if one small value is at the end of the array but very slowly if large value is at the begging of it

## Advanced sorts

# Chapter 3 - Recursive algorithms

> TODO:
> Hilbert curves and Sierpinski curves

> TODO:
> Revisit the exercises and algos for Stable Marriage -> End

In the other news backtracking with Knight's tour and 8 Queens problem, nothing new there to say...

One thing to be noted for representation of the data for he Queens problem

- `bool row[8]` => represent the rows which one queen has taken
- `bool col[8]`
- `bool dbltr[15]` => *each diagonal from bottom left to top right* has the same sum of the coordinates on it (8r1c = 7r2c = 6r3c = ...)
- `bool dtlbr[15]` => *each diagonal from top left to bottom right* has a constant difference of the coords (8r7c = 7r6c = 6r5c = ...) and to keep them all positive add 7 to the difference


# Chapter 4 - Dynamic information structures

> TODO
> Implement Topological sort

> TODO
> Implement the pagination B-tree

to implement a B-tree (a tree with more than 2 children) use a linked list as "value" and then "value" of each of the nodes in the list is another tree

big trees (>10^6 elemts) require a some structuring scheme
- every page has at least n elements - except root
- every page has at most 2\*n elements
- every page is either a leaf page or it has m+1 elements where m is number of keys in that page
- all leaf pages appear on the same level

Insertion to B-tree:
- if there is less than 2\*n elements in the page just insert it
- if there is 2\*n elements already in the page:
    - insert the split the elements in two groups and create two pages of size n
    - insert the middle element in the parent page

Deletion is inverse of insertion

> TODO
> More investigation of the SBB-tree (symmetric binary B-tree) and red-black trees (same thing actually)


