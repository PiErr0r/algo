# Chapter 3 - Recursive algorithms

> TODO:
> Hilbert curves and Sierpinski curves

In the other news backtracking with Knight's tour and 8 Queens problem, nothing new there to say...

One thing to be noted for representation of the data for he Queens problem

- `bool row[8]` => represent the rows which one queen has taken
- `bool col[8]`
- `bool dbltr[15]` => *each diagonal from bottom left to top right* has the same sum of the coordinates on it (8r1c = 7r2c = 6r3c = ...)
- `bool dtlbr[15]` => *each diagonal from top left to bottom right* has a constant difference of the coords (8r7c = 7r6c = 6r5c = ...) and to keep them all positive add 7 to the difference


