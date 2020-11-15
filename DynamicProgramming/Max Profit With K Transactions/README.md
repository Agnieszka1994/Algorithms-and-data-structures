# Max Profit With K Transactions

This function takes in an array of positive integers representing the prices of a single stock on various days and an integer `K`, which represents the number of transactions allowed, and returns the maximum profit that can be made by buying and selling the stock, given `K` transactions.

It is allowed to hold only one share of the stock at a time and all `K` transactions must be used. 


### Sample Input
```javascript
prices = [5, 11, 3, 50, 60, 90]
k = 2

```
### Sample Output
```javascript
93 // buy 5, sell 11, buy 3, sell 90
```
### Space and Time complexity
O(nk) time | O(n) space - where n is the number of prices and k is the number of transactions.
