# Find Closest Value In BST

This function takes in a Binary Search Tree and a target integer value, and returns the closest value to that target value contained in the BST. \

Each `BST` node has an integer value, a `left` child node, and a `right` child node. A node is said to be valid `BST` if it satisfies the BST property: its `value` is strictly grater that the value of every node to its left and its `value` is less or equal to the values of every node to its right, and its children nodes are either valid `BST` nodes themselves or `nullptr`/`NULL`.

### Sample Input
```javascript

tree =       10
           /    \
          5      15
        /   \   /  \
       2     5 13   22
      /          \ 
     1            14

target = 12
```
### Sample Output
```javascript
13
```
### Space and Time complexity
Average: O(log(n)) time | O(1) space - where n is the number of nodes in the BST. \
Worst: O(n) time | O(1) space  