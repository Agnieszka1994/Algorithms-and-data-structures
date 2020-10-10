# Flatten Binary Tree

This function takes in a Binary Tree, flattens it and returns its leftmost node. 
A flattened binary tree is a structure that's nearly identical to a doubly linked list(except taht nodes have `left` and `right` pointers instead of `prev` and `next`), where nodes follow the original tree's left-to-right order. 

Each Binary Tree node has an integer value, a left child node and a right child node. Children can either be Binary Tree nodes or nullptr.

### Sample input
```javascript
 tree =       1
            /   \
           2     3
          / \   / 
         4   5 6
            / \
           7   8  

```
### Sample output
 ```javascript
 4 <-> 2 <->  7 <-> 5 <->  8 <-> 1 <-> 6 <-> 3 // leftmost node with value 4
```
 ### Space and Time complexity
O(n) Time | O(d) Space - where "n" is the number of nodes in the Binary Tree and "d" is the depth of the Binary Tree.
