# Largest Range 

This function takes in an array of integers and returns and array of length 2 representing the largest range of the integers contained in the input array. 

A range of numbers is defined as a set of numbers that come right after each other in the set of real integers. For example, the output array `[2, 8]` represents the range `[2, 3, 4, 5, 6, 7, 8]`, which is a range of length 7.

The input array doesn't need to be sorted.

### Sample Input
```javascript
array = [1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6]
```
### Sample Output
```javascript
[0, 7]

```
### Space and Time complexity
O(n) time | O(n) space - where n is the length of the input array.
