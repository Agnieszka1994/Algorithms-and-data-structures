# Number Of Binary Tree Topologies

This function takes in a non-negative integer `n` and returns the number of possible Binary Tree topologies that can be created with exactly `n` nodes.

A BT topology is defined as any Binary Tree configuration, irrespective of node values.
When `n` is equal to `0` there is `1` topology that can be created - the `nullptr`. 

### Sample Input
```javascript
n = 3
```
### Sample Output
```javascript
5
// the below trees can be created: 
  0      0      0          0      0
 /        \      \        /      / \
0          0      0      0      0   0
 \        /        \    /
  0      0          0  0
```
### Space and Time Complexity
O(n^2) time | O(n) space where n is the input number.