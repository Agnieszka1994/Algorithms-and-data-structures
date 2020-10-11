# Permutations

This function takes in an array of unique integers and returns an array of all permutations of those integers. If the input array is empty, the function returns an empty array.

### Sample Input
```javascript
array = [1, 2, 3]
```
### Sample Output
```javascript
[[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
```
### Space and Time complexity 
`O(n*n!) Time` | `O(n*n!)` Space - where n is the number of elements in the input array.