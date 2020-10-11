# Right Smaller Than

This function takes in an array of integers and returns an array of the same length, where each element in the output array corresponds to the number of integers in the input array that are to the right of the releveant index and that are strictly smaller that the integer at that index. 

The value at `outputArray[i]` represents the number of integers that are to the right of `i` and that are strictly  smaller than `inputArray[i]`.

The function uses `SpecialBST` class to solve this problem. The class is implemented in the same file.

### Sample Input
```javascript
array = [8, 5, 11, -1, 3, 4, 2]
```
### Sample Output
```javascript
[5, 4, 4, 0, 1, 1, 0]
```
### Space and Time Complexity
Average: O(nlog(n)) time | O(n) space - where n is the length of the input array (when the `SpecialBST` is balanced). \
Worst: O(n^2) time | O(n) space (when the `SpecialBST` is a linked list).