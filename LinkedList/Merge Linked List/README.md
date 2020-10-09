# Merge Linked List

This function takes in the heads of two Singly linked Lists that are in sorted order, respectively, merges the lists in place and returns the head of the merged list. 

Each `LinkedList` node has an integer value, `next` pointer to the next node in the list or to `nullptr` if it's the tail of the list. 

### Sample input
```javascript
headOne = 2 -> 6 -> 7 -> 8  //head with value 2
headTwo = 1 -> 3 -> 4 -> 5 -> 9 -> 10 //head with value 1
```
### Sample output
```javascript
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 //new head with value 1
```
### Space and Time complexity

O(n+m) time | O(1) space - where "n" is the number of nodes in the first Linked List and "m" is the number of nodes in the second Linked List.
