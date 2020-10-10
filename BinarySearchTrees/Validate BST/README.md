# Validate BST

This function takes in a potentially invalid `BST` and returns a boolean representing whether the BST is valid.

Each `BST` node has an integer value, a `left` child node, and a `right` child node. A node is said to be valid `BST` if it satisfies the BST property: its `value` is strictly grater that the value of every node to its left and its `value` is less or equal to the values of every node to its right, and its children nodes are either valid `BST` nodes themselves or `nullptr`/`NULL`.

### Sample Input
```javascript
tree =       10
           /    \
          5      15
        /   \   /  \
       1     5 13   22
              \      \
               7      81
```
### Sample Output
```javascript
true
```
### Space and Time complexity
O(n) time | O(d) space - where n is the number of nodes in the BST and d is the depth of the BST. 
 