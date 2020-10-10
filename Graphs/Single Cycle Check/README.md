# Single Cycle Check

This function takes in an array of integers and returns a boolean representing whether the `jumps` in the array form a single cycle. 

Each integer in the input array represents a `jump` of its value in the array. For instance, the integer `2` represents a `jump` of two indices forward in the array; the integer `3` represents a jump of three indices backward in the array. 

A single cycle occurs, if starting at any index in the array and following the jumps, every element in the array is visited exactly once before landing back on the starting index. If a jump spills past the array's bounds, it wraps over to the other side (a jump of `-1` at index `0` brings us to the last index in the array, a jump of `1` at the last index brings us to index `0`). 

### Sample Input
```javascript
array = [2, 3, 1, -4, -4, 2]
```

### Sample Output
```javascript
true
```
### Space and Time complexity
O(n) time | O(1) space - where n is the length of the input array.
