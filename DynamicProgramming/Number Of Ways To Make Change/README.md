# Number Of Ways To Make Change

This function takes in an array of distinct positive integers representing coin denominations and a single non-negative integer `n` representing a target amount of money, and returns the numbers of ways to make change for the target amount using the given coin denominations.

### Sample Input
```javascript
targetAmount = 6
denominations = [1, 5]
```
### Sample Output
```javascript
2 // 1x1 + 1x5  or 6x1
```
### Space and Time complexity
O(nd) time | O(n) space - where n is the target amount and d is the number of coin denominations.
