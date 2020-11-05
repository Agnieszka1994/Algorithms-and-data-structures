# Knapsack Problem

We are given an array of arrays where each subarray represents an item; the first integer is the item's value, and the second integer is the item's weight. We are also given an integer representing the maximum capacity of a knapsack.
This function takes in the above data and returns the maximized combined value of the items which can fit in a knapsack without exceeding its capacity, as well as an array of indices of each item.

### Sample Input
```javascript
items = [[1, 2], [4, 3], [5, 6], [6, 7]]
capacity = 10

```
### Sample Output
```javascript
items = [1, 3]  //items [4, 3] and [6, 7]
totalValue = 10
```
### Space and Time complexity
O(nc) time | O(nc) space - where n is the number of items and c is the capacity.
