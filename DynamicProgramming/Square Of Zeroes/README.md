# Square Of Zeroes

This function takes in a square-shaped matrix of only `1`s and `0`s and returns a boolean representing whether the input matrix contains a square whose borders are made up of only `0`s.

### Sample Input
```javascript
matrix = [
  [1, 1, 1, 0, 1, 0], 
  [0, 0, 0, 0, 0, 1], 
  [0, 1, 1, 1, 0, 1],
  [0, 0, 0, 1, 0, 1], 
  [0, 1, 1, 1, 0, 1], 
  [0, 0, 0, 0, 0, 1],
]
```
### Sample Output
```javascript
true 
/*
  [ ,  ,  , 0,  , 0], 
  [0, 0, 0, 0, 0,  ], 
  [0,  ,  ,  , 0,  ],
  [0, 0, 0,  , 0,  ], 
  [0,  ,  ,  , 0,  ], 
  [0, 0, 0, 0, 0,  ],
*/
```
### Space and Time complexity
O(n^3) time | O(n^2) space - where n is the height and width of the matrix.
