# Node Depths

This function takes in a Binary Tree and returns the sum of its nodes' depths (sum of distances between the root and each node in the Binary Tree).

Each `Binary Tree` node has an integer `value`, a `left` child node and a `right` child node. Children can either be `Binary Tree` nodes or `nullptr`.

### Sample input
```javascript
Ttree =       1
            /   \
           2     3
          / \   / \
         4   5 6   7
        / \
       8   9
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