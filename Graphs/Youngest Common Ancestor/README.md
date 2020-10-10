# Youngest Common Ancestor

This function takes in three nodes, all of which are instances of an `Ancestral Tree` class, and returns the youngest common ancestor to the two descendants.
The first input is the top ancestor in the ancestral tree (the only instance that has no ancestor - its `ancestor` property points to `nullptr`), and the other two inputs are descendants in the ancestral tree.

 Each `Ancestral Tree` node has an `ancestor` property pointing to its youngest ancestor.
A descendant is considered its own ancestor - so in the tree below, the youngest common ancestor to nodes `A` and `B` is node `A`. 
```javascript
     A //A is the youngest common ancestor
    /
   B
```
### Sample Input
```javascript
topAncestor = node A
descendantOne = node E
descendantTwo = node I

AncestralTree =   A
               /     \
              B       C
             / \     / \
            D   E   F   G
           / \    
          H   I    
```

### Sample Output
```javascript
node B
```
### Space and Time complexity
O(d) time | O(1) space - where dis the depth of the ancestral tree.
