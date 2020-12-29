# Chapter 2 - Sorting

> TODO:
> Go over sequence sorting once again for better comprehension

use `cc chapter02.c helpers.c sorting.` to compile chapter02 code

## Simple sorts
Insertion sort - when found item which is smaller than previous go down the list and insert it in the place where it isn't smaller than the previous item
Binary insertion sort - intuitively it reduces the number of comparisons but upon closer inspection it is found out to be less efficient than its first implementation, and the number of swaps remains the same
Selection sort - find a smallest number in the remaining array and replace it with the currently inspected one if it is (j goes from 1 to n, then from 2 to n, ...);
Bubble sort - swap values if `a > b` and `a_i < b_i`
Shake sort - imroved bubble sort to gor forward to backwards and backwards to forwards so you improve the assymetry of normal bubble sort which will sort the array fast if one small value is at the end of the array but very slowly if large value is at the begging of it

## Advacned sorts

