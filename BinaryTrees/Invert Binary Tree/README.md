# Invert Binary Tree

This function takes in a `Binary Tree` and inverts it (swaps every left node in the Binary Tree for its corresponding right node).

Each `Binary Tree` node has an integer `value`, a `left` child node and a `right` child node. Children can either be `Binary Tree` nodes or `nullptr`.

### Sample input
```javascript
Ttree =       1
            /   \
           2     3
         / \    / \
        4   5  6   7
      / \   
     8   9  
```
### Sample output
 ```javascript
              1
            /   \
           3     2
         / \    / \
        7   6  5   4
                  / \   
                 9   8  
```
 ### Space and Time complexity
O(n) Time | O(d) Space - where "n" is the number of nodes in the Binary Tree and "d" is the depth of the Binary Tree.
