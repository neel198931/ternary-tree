ternary-tree
------------------------
The data structure for the Ternary Tree search tree are nodes that contain 3 leafs pointers 
as well as a linked list to hold the data structures. The structures inside of the
linkedlist will be kept in ascending order, values will go from smallest to largest,
and contain no more than 3 values at once. 

The files linkedList.h and linkedList.c contain both the function 
definitions and the function implementations for the linkedlist data structure. 
Something to note is when items are added to the linkedlist, they are
added in sorted order. So the smallest value in the linkedList will be at the head
and the largest value will be at the tail.
