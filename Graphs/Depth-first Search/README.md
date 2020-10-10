# Depth-first Search

This function is implemented on the `Node` class. It takes in an empty array, traverses the tree using the `Depth-first Search` approach(navigating the tree from left to right), stores all of the nodes' names in the input array, and returns it. 

Each `Node` has a `name` and an array of optional `children` nodes. When put together, nodes form an acyclic tree-like structure.

### Sample Input
```javascript
graph =    A
        /  |  \
       B   C   D
      / \     / \
     E   F   G   H
        / \   \
       I   J   K
```

### Sample Output
```javascript
["A", "B", "E", "F", "I", "J", "C", "D", "G", "K", "H"]
```
### Space and Time complexity
O(v+e) time | O(v) space - where v is the number of vertices of the input graph and e is the number of edgesof the input graph.
