# River Sizes

This function takes in a two-dimentional array of potentially unequal height and width containing only `0`s and `1`s. Each `0` represents land, and each `1` represents part of a river. A river consists of any number of `1` that are either hirizontally or vertically adjacent (but not diagonally). The number of adjacent `1`s forming a river determines its size.
The function returns an array of the sizes of all rivers represented in the input matrix.

### Sample Input
```javascript
matrix = [
  [1, 0, 0, 1, 0],
  [1, 0, 1, 0, 0],
  [0, 0, 1, 0, 1],
  [1, 0, 1, 0, 1],
  [1, 0, 1, 1, 0]
]
```

### Sample Output
```javascript
[1, 2, 2, 2, 5]
/*
the rivers can be clearly seen below:
  [1,  ,  , 1,  ],
  [1,  , 1,  ,  ],
  [ ,  , 1,  , 1],
  [1,  , 1,  , 1],
  [1,  , 1, 1,  ]

*/
```
### Space and Time complexity
O(n) time | O(1) space - where n is the length of the input array.
