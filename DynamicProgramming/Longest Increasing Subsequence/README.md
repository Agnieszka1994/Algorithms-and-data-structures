# Longest Increasing Subsequence

This function takes in a non-empty array of integers and returns the longest strictly-increasing subsequence in the array.
A subsequence of an array is a set of numbers that are not necessarily adjacent in the array, but that are in the same order as they appear in the array.
The numbers `[1, 3, 5]` form a subsequence of the array `[1, 2, 3, 4, 5]`, 
and so the numbers `[2, 4]`. A single number and the array itself are both valid subsequences of the array.

### Sample Input
```javascript
array = [5, 7, -24, 12, 10, 2, 3, 12, 5, 6, 35]
```
### Sample Output
```javascript
[-24, 2, 3, 5, 6, 35]
```
### Space and Time complexity
O(nlog(n)) time | O(n) space - where n is the length of the input array.
