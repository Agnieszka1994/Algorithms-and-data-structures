# A* Algorithm
 This function takes in a two-dimensional array and four integers `startRow`, `startCol`, `endRow` and `endCol`, finds the shortest path netween the start node and the end node using the `A* algorithm` and returns it.

 The array contains only `0`s and `1`s, where each `0` represents a free space and each `1` represents an obstacle.
 The shortest path is returned as an array of node positions `[row, col]`.

 ### Sample Input
```javascript
startRow = 0;
startCol = 1;
endRow = 4;
endCol = 3;
graph = [
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 0],
    [1, 0, 1, 1, 1],
    [0, 0, 0, 0, 0]
]
```
 ### Sample Output
```javascript
[[0, 1], [0, 0], [1, 0], [2, 0], [2, 1], [3, 1], [4, 1], [4, 2], [4, 3]]  

/* the shortest path marked with x's:
    [x  x         ]
    [x  1  1  1   ]
    [x  x         ]
    [1  x  1  1  1]
    [   x  x  x   ]
*/
```
 ### Space and Time complexity
O(w * h * log(w * h)) time | O(w * h) space - where w is the width of the graph and h is the height.