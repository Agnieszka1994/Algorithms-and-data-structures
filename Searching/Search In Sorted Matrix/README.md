# Search In Sorted Matrix

This function takes in a two-dimentional array of distinct integers and a target integer and returns an array of the row and column indices of the target integer if it's contained in the matrix, otherwise `[-1, -1]`. 
Each row in the matrix is sorted, and each column is also sorted. The matrix doesn't have to have the same height and width.

### Sample Input
```javascript
matrix = [
  [1, 4, 7, 12, 15, 1000],
  [2, 5, 19, 31, 32, 1001],
  [3, 8, 24, 33, 35, 1002],
  [40, 41, 42, 44, 45, 1003],
  [99, 100, 103, 106, 128, 1004]
]
```
### Sample Output
```javascript
[3, 3]
```
### Space and Time complexity
O(n + m) time | O(1) space - where n is the length of the matrix's row and m is the length of the matrix's columns.