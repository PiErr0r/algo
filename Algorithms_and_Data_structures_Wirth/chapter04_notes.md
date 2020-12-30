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


