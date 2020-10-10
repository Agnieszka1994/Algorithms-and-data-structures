# Min Height BST

This function takes in a non-empty sorted array of distinct integers, constructs a BST from the integers, and returns the root of the BST. The function minimizes the height of the BST.\

The function uses `BST` class implemented in the same file. \
The `BST` class supports `insert` method used by the function. 

Each `BST` node has an integer value, a `left` child node, and a `right` child node. A node is said to be valid `BST` if it satisfies the BST property: its `value` is strictly grater that the value of every node to its left and its `value` is less or equal to the values of every node to its right, and its children nodes are either valid `BST` nodes themselves or `nullptr`/`NULL`.

### Sample Input
```javascript
array = [1, 2, 5, 7, 10, 13, 14, 15, 22]
```
### Sample Output
```javascript
             10
           /    \
          2      14
        /   \   /  \
       1     5 13   15
              \      \
               7      22
//this is one example of a BST with min height
```
### Space and Time complexity
O(n) time | O(n) space - where n is the number of nodes in the BST. \
 