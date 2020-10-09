# Iterative in order traversal

This function takes in a Binary Tree and Traverses it iteratively using the in-order tree-traversal technique. As the tree is being traversed, a callback function passed in as an argument to the main function is called on each node.

Each Binary Tree node has an integer value, a left child node,a right child node and **an additional pointer to their parent node**. Children can either be Binary Tree nodes or nullptr.

### Sample input
```javascript
Tree = [
    {
    "nodes": [
        {"id": "1", "left": "2", "right": "3", "value": 1},
        {"id": "2", "left": "4", "right": null, "value": 2},
        {"id": "3", "left": "6", "right": "7", "value": 3},
        {"id": "4", "left": null, "right": "9", "value": 4},
        {"id": "6", "left": null, "right": null, "value": 6},
        {"id": "7", "left": null, "right": null, "value": 7},
        {"id": "9", "left": null, "right": null, "value": 9}
    ],
    "root": "1"
    }
]

callback = someCallback;
```
### Sample input

callback(4)
callback(9)
callback(2)
callback(1)
callback(6)
callback(3)
callback(7)

### Space and Time Complexity
O(n) Time | O(1) Space - where "n" is the number of nodes in the Binary Tree.