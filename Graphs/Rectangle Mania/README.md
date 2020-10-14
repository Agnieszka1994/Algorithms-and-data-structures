# Rectangle Mania

This function takes in a list of Cartesian coordinates and returns the number of rectangles formed by these coordinates.
Only rectangles with sides parallel to the x and y axes are counted (no diagonal sides).

### Sample input
```javascript
coordinates = [
    [0, 0], [0, 1], [1, 1], [1, 0], 
    [2, 1], [2, 0], [3, 1], [3, 0]
]
```
### Sample output
```javascript
6
```
### Space and Time complexity
O(n^2) time | O(n) space - where n is the number of coordinates.