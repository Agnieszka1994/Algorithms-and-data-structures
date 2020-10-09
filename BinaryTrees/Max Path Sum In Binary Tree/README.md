# Max Path Sum in Binary Tree

This function takes in a Binary Tree and returns its Max Path Sum.
A path is a collection of connected nodes in a tree where no node is connected to more than two other nodes; a path sum is the sum of the values of the nodes in a particular path.

Each Binary Tree node has an integer value, a left child node and a right child node. Children can either be Binary Tree nodes or nullptr.

### Sample input
```javascript
Tree = [
    {
    "nodes": [
        {"id": "1", "left": "2", "right": "3", "value": 1},
        {"id": "3", "left": "6", "right": "7", "value": 3},
        {"id": "7", "left": null, "right": null, "value": 7},
        {"id": "6", "left": null, "right": null, "value": 6},
        {"id": "2", "left": "4", "right": "5", "value": 2},
        {"id": "5", "left": null, "right": null, "value": 5},
        {"id": "4", "left": null, "right": null, "value": 4}
    ],
    "root": "1"
    }
]
```
### Sample input

18 - // 5 + 2 + 1 + 3 + 7

### Space and Time Complexity
O(n) Time | O(log(n)) Space - where "n" is the number of nodes in the Binary Tree.