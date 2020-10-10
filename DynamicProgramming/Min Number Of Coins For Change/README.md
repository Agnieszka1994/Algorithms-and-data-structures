# Min Number Of Coins For Change

This function takes in an array of positive integers representing coin denominations and a single non-negative integer `n` representing a target amount of money, and returns the smallest number of coins needed to make change for that target amount using the given coin denominations.
If it's impossible to make change for the target amount, the function returns `-1`.

### Sample Input
```javascript
targetAmount = 7
denominations = [1, 5, 10]
```
### Sample Output
```javascript
3 // 3 is the minimum number of coins - 2x1 + 1x5 
```
### Space and Time complexity
O(nd) time | O(n) space - where n is the target amount and d is the number of coin denominations.
