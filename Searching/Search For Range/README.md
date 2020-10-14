# Search For Range

This function takes in a sorted array of integers as well as a target integer and returns a range of indices (in the form of an array) in between which the target number is contained in the array.

The first number in the output array represents the first index at which the target number is located; the second number represents the last index. If the target integer is not located in the array, the function returns `[-1, -1]`.

### Sample Input
```javascript
array = [0, 1, 21, 33, 45, 45, 45, 45, 45, 45, 61, 71, 73]
target = 45
```
### Sample Output
```javascript
[4, 9]
```
### Space and Time complexity
O(nlog(n)) time | O(1) space - where n is the length of the input array.