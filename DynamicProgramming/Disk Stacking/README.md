# Disk Stacking

This function takes in a non-empty array of arrays where each subarray holds 3 integers representing a disk, and returns an array of disks in the `maximum height` stack.

The integers in the subarrays represent each disk's width, depth and height in the format: `[width, depth, height]`. The goal is to stack up the disks and to maximize the total `height` of the stack. A disk must have a strictly smaller `width, depth and height than any other disk below it.


### Sample Input
```javascript
disks = [[2, 1, 2], [3, 2, 3], [2, 2, 8], [2, 3, 4], [1, 3, 1], [4, 4, 5]]

```
### Sample Output
```javascript
[2, 1, 2], [3, 2, 3], [4, 4, 5]] 
```
### Space and Time complexity
O(n^2) time | O(n) space - where n is the number of disks.
