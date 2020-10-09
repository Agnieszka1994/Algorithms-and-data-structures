# Shift Linked List

This function takes in a singly linked list and an integer `k`, shifts the list in place (it does not create a brand new list) by k positions, and returns its new head.

Shifting a Linked List means moving its nodes forward or backward and wrapping them around the list where appropriate.
Whether nodes are moved forward or backward is determined by whether `k` is positive or negative. 

Each `LinkedList` node has an integer value, `next` pointer to the next node in the list or to `nullptr` if it's the tail of the list. 

### Sample input
```javascript
head = 0 -> 1 -> 2 -> 3 -> 4 -> 5 //head with value 0
k = 2
```
### Sample output
```javascript
head = 4 -> 5 -> 0 -> 1 -> 2 -> 3 //head with value 4
```
### Space and Time complexity

O(n) time | O(1) space - where "n" is the number of nodes in the Linked List
