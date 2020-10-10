# BST Traversal

This file contains three functions that take in a Binary Search Tree and an empty array, traverse the BST, add its nodes' values to the input array and returns that array. \

The three functions traverse the BST u-order, pre-order, and post-order tree-traversal techniques, respectively. \

Each `BST` node has an integer value, a `left` child node, and a `right` child node. A node is said to be valid `BST` if it satisfies the BST property: its `value` is strictly grater that the value of every node to its left and its `value` is less or equal to the values of every node to its right, and its children nodes are either valid `BST` nodes themselves or `nullptr`/`NULL`.


### Sample Input
```javascript

tree =       10
           /    \
          5      15
        /   \      \
       2     5      22
      /            
     1  

array = []
```
### Sample Output
```javascript
inOrderTraverse: [1, 2, 5, 5, 10, 15, 22]
preOrderTraverse: [10, 5, 2, 1, 5, 15, 22]
postOrderTraverse: [1, 2, 5, 5, 22, 15, 10]
```
### Space and Time complexity
All methods: O(n) time | O(n) space - where n is the number of nodes in the BST.