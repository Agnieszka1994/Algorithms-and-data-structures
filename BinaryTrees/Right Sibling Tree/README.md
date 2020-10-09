# Right Sibling Tree

This function takes in a Binary Tree, transforms it into a Right Sibling Tree and returns its root. 
A Right Sibling Tree is obtained by making every node in a binary tree have its **right** property point to its right sibling instead of its right child. A node's right sibling is the node immediately to its right on the same level or **nullptr** if there is no node immediately to its right. 
Once the transformation is complete, some nodes might no longer have a node pointing to them (and are effectively unreachable). 

Each Binary Tree node has an integer value, a left child node and a right child node. Children nodes can either be Binary Tree nodes or nullptr. 

### Space and Time complexity
O(n) time | O(d) space - where "n" is the number of nodes in the Binary Tree and "d" is the depth of the Binary Tree. 