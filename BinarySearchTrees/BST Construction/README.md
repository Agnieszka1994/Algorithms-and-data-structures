# Project Title

This file contains a class `BST` for a Binary Search Tree. \
The class supports:
- Inserting values with the `insert` method.
- Removing values with the `remove` method; this method remove only the first instance of a given value. Calling the `remove` method on a single-node tree doesn't do anything. 
- Searching for values with the `contains` method. \

Each `BST` node has an integer value, a `left` child node, and a `right` child node. A node is said to be valid `BST` if it satisfies the BST property: its `value` is strictly grater that the value of every node to its left and its `value` is less or equal to the values of every node to its right, and its children nodes are either valid `BST` nodes themselves or `nullptr`/`NULL`.


### Sample Usage
```javascript
//we are given the following tree:

                10
              /     \
             5      15
           /   \   /   \
          2     5 13    22
        /           \
       1             14

//all operations below are performed sequentially
insert(12):
                10
              /     \
             5      15
           /   \   /   \
          2     5 13    22
        /        /  \
       1        12   14

remove(10):
                12
              /     \
             5      15
           /   \   /   \
          2     5 13    22
        /           \
       1             14

contains(15): true
 ```

### Space and Time complexity
Average(all methods): O(log(n)) time | O(1) space - where n is the number of nodes in the BST. \
Worst(all methods): O(n) time | O(1) space