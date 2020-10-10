# All Kinds of Node Depths

This function takes in a Binary Tree and returns the sum of its subtrees' nodes' depths (sum of distances between the root and each node in each subtree).

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
```javascript
26 
//The sum of the root tree's node depths is 16.
//The sum of the tree rooted at 2's node depths is 6.
//The sum of the tree rooted at 3's node depths is 2.
//The sum of the tree rooted at 4's node depths is 2.
//Etc...
//The sum of all of these depths sums is 26.
```
### Space and Time complexity
O(n) time | O(d) space - where "n" is the number of nodes in the Binary Tree and "d" is the depth of the Binary Tree. 