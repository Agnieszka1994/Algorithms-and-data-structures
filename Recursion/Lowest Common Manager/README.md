# Lowest Common Manager

This function takes in three inputs, all of which are instances of an `OrgChart` class. The first input is the top manager in the Org Chart, and the other two inputs are reports in the organizational chart. The function returns the lowest common manager for the two reports (they have to be distinct). 

Each `OrgChart` has a `name` character and `directReports` property pointing to their directs reports.

### Sample Input
```javascript
topManager = A
reportOne = E
reportTwo = I

           A
        /     \
       B       C
     /   \   /   \
    D     E F     G
  /   \
 H     I
```
### Sample Output
```javascript
Node B
```
### Space and Time complexity 
O(n) Time | O(d) Space - where n is the number of nodes in the OrgChart and d is the depth of the orgChart.