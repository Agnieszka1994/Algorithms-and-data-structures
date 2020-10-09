# Remove Kth Node From End

This function takes in a singly linked list and an integer `k` and removes the kth node from the end of the list. The removal is done in place - the original data structure is mutated. 

Each `LinkedList` node has an integer value, `next` pointer to the next node in the list or to `nullptr` if it's the tail of the list. 

### Sample input
```javascript
head = 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 //head with value 0
k = 4
```
### Sample output
```javascript
//kth node from the end of the list is removed (node with value 6)
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 7 -> 8 -> 9 
```
### Space and Time complexity

O(n) time | O(1) space - where "n" is the number of nodes in the Linked List
