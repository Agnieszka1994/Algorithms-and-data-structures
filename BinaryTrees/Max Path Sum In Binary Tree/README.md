# Max Path Sum in Binary Tree

This function takes in a `Binary Tree` and returns its Max Path Sum.
A path is a collection of connected nodes in a tree where no node is connected to more than two other nodes; a path sum is the sum of the values of the nodes in a particular path.

Each `Binary Tree` node has an integer `value`, a `left` child node and a `right` child node. Children can either be `Binary Tree` nodes or `nullptr`.

### Sample input
```javascript
Ttree =       1
            /   \
           2     3
          / \   / \
         4   5 6   7
```
### Sample output
```javascript
18 - // 5 + 2 + 1 + 3 + 7
```
### Space and Time Complexity
O(n) Time | O(log(n)) Space - where "n" is the number of nodes in the Binary Tree.