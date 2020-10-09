# Node Depths

This function takes in a Binary Tree and returns the sum of its nodes' depths (sum of distances between the root and each node in the Binary Tree).

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

16 \
\
The depth of the node with value 2 is 1.\
The depth of the node with value 3 is 1.\
The depth of the node with value 4 is 2.\
The depth of the node with value 5 is 2.\
The depth of the node with value 8 is 3.\
Etc...\
The sum of all of these depths is 16.

### Space and Time complexity
O(n) time | O(d) space - where "n" is the number of nodes in the Binary Tree and "d" is the depth of the Binary Tree. 