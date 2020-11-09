# Rearrange Linked List

This function takes in the head of a singly linked list and an integer `k`, rearranges the list in place around the nodes with value `k`, and returns its new head. 

Rearranging a linked list around nodes with value `k` means moving all nodes with value smaller than `k` before all nodes with value `k` and all nodes with value greater than `k` after all nodes with value `k`.
All moved nodes maintain their original relative order. The list is rearranges even if it does not have any nodes with value `k`.

Each `LinkedList` node has an integer value, `next` pointer to the next node in the list or to `nullptr` if it's the tail of the list.

### Sample input
```javascript
head = 3 -> 0 -> 5 -> 2 -> 1 -> 4  // head with value 3
k = 3
```
### Sample output
```javascript
// new head with value 0; nodes 0, 2, 1 and 5, 3 maintained their original ordering
0 -> 2 -> 1 -> 3 -> 5 -> 4 
```
### Space and Time complexity

O(n) time | O(1) space - where "n" is the number of nodes in the Linked List
