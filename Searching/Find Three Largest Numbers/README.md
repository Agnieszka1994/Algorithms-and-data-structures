# Find Three Largest Numbers

This function takes in an array of at least three integers and, without sorting the input array, returns a sorted array of the three largest integers in the input array. 
If necessary, the function returns duplicate integers; for example - it returns `[10, 10, 12]` for an input array of `[10, 5, 9, 10, 12]`.

### Sample Input
```javascript
array = [141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]
```
### Sample Output
```javascript
[18, 141, 541]
```
### Space and Time complexity
O(n) time | O(1) space - where n is the length of the input array.