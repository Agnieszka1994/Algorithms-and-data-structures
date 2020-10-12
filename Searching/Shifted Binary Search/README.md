# Shifted Binary Search

This function takes in a sorted array of distinct integers as well as a target integer.
The integers in the array have been shifted by some amount (they have been moved to the left of to the right), for example, `[1, 2, 3, 4, 5]` might have turned into `[3, 4, 5, 1, 2]`.
The function uses a variation of the Binary Search algorithm to determine if the target integer is contained in the array and returns its index, otherwise `-1`.

### Sample Input
```javascript
array = [45, 61, 71, 72, 73, 0, 1, 21, 33, 37]
]
```
### Sample Output
```javascript
8
```
### Space and Time complexity
O(log(n)) time | O(1) space - where n is the length of the input array.