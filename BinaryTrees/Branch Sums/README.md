# Branch Sums

This function takes in a Binary Tree and returns a list of its branch sums ordered from leftmost branch sum to rightmost branch sum. A branch sum is the sum of all values in a Binary Tree branch.

Each Binary Tree node has an integer value, a left child node and a right child node. Children nodes can be either Binary Tree nodes or nullptr. 

### Sample input 
```javascript
{
  "nodes": [
    {"id": "1", "left": "2", "right": "3", "value": 1},
    {"id": "2", "left": "4", "right": "5", "value": 2},
    {"id": "3", "left": "6", "right": "7", "value": 3},
    {"id": "4", "left": "8", "right": "9", "value": 4},
    {"id": "5", "left": "10", "right": null, "value": 5},
    {"id": "6", "left": null, "right": null, "value": 6},
    {"id": "7", "left": null, "right": null, "value": 7},
    {"id": "8", "left": null, "right": null, "value": 8},
    {"id": "9", "left": null, "right": null, "value": 9},
    {"id": "10", "left": null, "right": null, "value": 10}
  ],
  "root": "1"
}
```
### Sample output
```javascript
[15, 16, 18, 10, 11]
```

### Space and Time complexity
O(n) time | O(n) space - where n is the number of nodes in the Binary Tree. 