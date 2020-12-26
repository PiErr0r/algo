# Chapter 1 - Fundamental data structures

Nothing new actually, already know what and how those work (int, float, bool, char, array) but Set is new (new as in not existent in C but it could be built with trees - TODO for later)
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
