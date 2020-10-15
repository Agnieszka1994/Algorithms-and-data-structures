# Min Number Of Jumps

This function takes in a non-empty array of positive integers where each integer represents the maximum number of steps you can take forward in the array, and returns the minimum number of jumps needed to reach the final index. 

For instance, if the element at index `1` is `3`, you can go from index `1` to index `2`, `3` or `4`.
Jumping from index `i` to index `i + x` is always counted as one jump.

### Sample Input
```javascript
array = [3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3]
```
### Sample Output
```javascript
4 

```
### Space and Time complexity
O(n) time | O(1) space - where n is the length of the input array.
