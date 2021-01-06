# Find successor

This function takes in a Binary Tree (where nodes have an additional pointer to their parent node) as well as a node contained in that tree and returns the given node's successor.

A node's successor is the next node to be visited when traversing its tree using the in-order traversal technique. A node has no successor if it's the last node to be visited - the function returns `nullptr`.

Each `Binary Tree` node has an integer `value`, a `left` child node and a `right` child node. Children nodes can be either `Binary Tree` nodes or `nullptr`. 

### Sample input 
```javascript
tree =       1
            /   \
           2     3
         / \    
        4   5  
      / 
     6
node = 5
```
### Sample output
```javascript
1
// 1 comes immediately after 5
```

### Space and Time complexity
O(h) time | O(1) space - where h is the height of the tree. 