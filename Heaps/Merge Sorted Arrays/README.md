# Merge Sorted Arrays

This function takes in a non-empty list of non-empty sorted arrays of integers and returns a merged list of all of those arrays. The integers are merged in sorted order. 

### Sample Input
```javascript
arrays = [
    [1, 5, 9, 21], 
    [-1, 0], 
    [-124, 81, 121], 
    [3, 6, 12, 20, 150]
]
```
### Sample Output
```javascript
[-124, -1, 0, 1, 3, 5, 6, 9, 12, 20, 21, 81, 121, 150]
```
### Space and Time complexity
`O(nlog(k) + k)` time |`O(n+k)` space - where n is the total number of array elements and k is the number of arrays.