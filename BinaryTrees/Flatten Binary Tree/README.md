# Flatten Binary Tree

This function takes in a Binary Tree, flattens it and returns its leftmost node. 
A flattened binary tree is a structure that's nearly identical to a doubly linked list(except taht nodes have **left** and **right** pointers instead of **prev** and **next**), where nodes follow the original tree's left-to-right order. 

Each Binary Tree node has an integer value, a left child node and a right child node. Children can either be Binary Tree nodes or nullptr.

### Sample input
```javascript
/* tree =     1
            /   \
           2     3
          / \   / 
         4   5 6
            / \
           7   8  
*/
{
  "nodes": [
    {"id": "1", "left": "2", "right": "3", "value": 1},
    {"id": "3", "left": "6", "right": null, "value": 3},
    {"id": "6", "left": null, "right": null, "value": 6},
    {"id": "2", "left": "4", "right": "5", "value": 2},
    {"id": "5", "left": "7", "right": "8", "value": 5},
    {"id": "8", "left": null, "right": null, "value": 8},
    {"id": "7", "left": null, "right": null, "value": 7},
    {"id": "4", "left": null, "right": null, "value": 4}
  ],
  "root": "1"
}
```
### Sample output
 
 4 <-> 2 <->  7 <-> 5 <->  8 <-> 1 <-> 6 <-> 3 // leftmost node with value 4

 ### Space and Time complexity
O(n) Time | O(d) Space - where "n" is the number of nodes in the Binary Tree and "d" is the depth of the Binary Tree.
