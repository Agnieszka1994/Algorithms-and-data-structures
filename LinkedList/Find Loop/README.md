# Find Loop

This function takes in the head of a Singly linked List that contains a loop (the list's tail points to some node in the linked list instead of `nullptr`). The function returns a pointer to the node from which the loop originates in constant space. 

Each `LinkedList` node has an integer value and `next` pointer to the next node in the list.

### Sample input
```javascript
head = 1 -> 2 -> 3 -> 4 -> 5 -> 6  //head with value 0
                      ^         v
                      9 <- 8 <- 7
```
### Sample output
```javascript
4 -> 5 -> 6  //the node with value 4
^         v
9 <- 8 <- 7 
```
### Space and Time complexity

O(n) time | O(1) space - where "n" is the number of nodes in the Linked List