# Iterative in order traversal

This function takes in a `Binary Tree` and Traverses it iteratively using the in-order tree-traversal technique. As the tree is being traversed, a callback function passed in as an argument to the main function is called on each node.

Each `Binary Tree` node has an integer `value`, a `left` child node,a `right` child node and an additional pointer to their `parent` node. Children can either be `Binary Tree` nodes or `nullptr`.

### Sample input
```javascript
Ttree =       1
            /   \
           2     3
         /      / \
        4      6   7
         \   
          9 

callback = someCallback;
```
### Sample input
```javascript
//the input callback called in the following order
callback(4)
callback(9)
callback(2)
callback(1)
callback(6)
callback(3)
callback(7)
```
### Space and Time Complexity
O(n) Time | O(1) Space - where "n" is the number of nodes in the Binary Tree.