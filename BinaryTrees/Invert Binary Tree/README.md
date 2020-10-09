# Invert Binary Tree

This function takes in a Binary Tree and inverts it (swaps every left node in the Binary Tree for its corresponding right node).

Each Binary Tree node has an integer value, a left child node and a right child node. Children can either be Binary Tree nodes or nullptr.

### Sample input
```javascript
{
  "nodes": [
    {"id": "1", "left": "2", "right": "3", "value": 1},
    {"id": "2", "left": "4", "right": "5", "value": 2},
    {"id": "3", "left": "6", "right": "7", "value": 3},
    {"id": "4", "left": "8", "right": "9", "value": 4},
    {"id": "5", "left": null, "right": null, "value": 5},
    {"id": "6", "left": null, "right": null, "value": 6},
    {"id": "7", "left": null, "right": null, "value": 7},
    {"id": "8", "left": null, "right": null, "value": 8},
    {"id": "9", "left": null, "right": null, "value": 9}
  ],
  "root": "1"
}
```
### Sample output
 ```javascript
 {
  "nodes": [
    {"id": "1", "left": "3", "right": "2", "value": 1},
    {"id": "2", "left": "5", "right": "4", "value": 2},
    {"id": "4", "left": "9", "right": "8", "value": 4},
    {"id": "8", "left": null, "right": null, "value": 8},
    {"id": "9", "left": null, "right": null, "value": 9},
    {"id": "5", "left": null, "right": null, "value": 5},
    {"id": "3", "left": "7", "right": "6", "value": 3},
    {"id": "6", "left": null, "right": null, "value": 6},
    {"id": "7", "left": null, "right": null, "value": 7}
  ],
  "root": "1"
}
```
 ### Space and Time complexity
O(n) Time | O(d) Space - where "n" is the number of nodes in the Binary Tree and "d" is the depth of the Binary Tree.
