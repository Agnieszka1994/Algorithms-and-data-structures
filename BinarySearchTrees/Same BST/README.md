# Same BSTs

This function takes in two arrays of integers and determines whether these arrays represent the same BST. An array is said to represent the BST obtained by inserting each integer in the array, from left to right, into the BST. \

A BST is a Binary Tree that consists only of `BST` nodes. \
Each `BST` node has an integer value, a `left` child node, and a `right` child node. A node is said to be valid `BST` if it satisfies the BST property: its `value` is strictly grater that the value of every node to its left and its `value` is less or equal to the values of every node to its right, and its children nodes are either valid `BST` nodes themselves or `nullptr`/`NULL`.

### Sample Input
```javascript
arrayOne = [10, 15, 8, 12, 94, 81, 5, 2, 11]
arrayTwo = [10, 8, 5, 15, 2, 12, 11, 94, 81]
```
### Sample Output
```javascript
true //both arrays represent the tree below
             10
           /    \
          8      15
        /       /  \
       5       12   94
     /        /    /
    2        11   81
```
### Space and Time complexity
O(n^2) time | O(d) space - where n is the number of nodes in each array, and d is the depth of the BST that they represent. 
 