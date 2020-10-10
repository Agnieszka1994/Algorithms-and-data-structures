# Max Sum Increasing Subsequence

This function takes in a non-empty array of integers and returns the greatest sum that can be generated from a strictly-increasing subsequence in the array as well as an array of the numbers in that subsequence.
A subsequence of an array is a set of numbers that are not necessarily adjacent in the array, but that are in the same order as they appear in the array.
The numbers `[1, 3, 5]` form a subsequence of the array `[1, 2, 3, 4, 5]`, 
and so the numbers `[2, 4]`. A single number and the array itself are both valid subsequences of the array.

### Sample Input
```javascript
array = [10, 70, 20, 30, 50, 11, 30]
```
### Sample Output
```javascript
[110 [10, 20, 30, 50]] 
// subsequence 10, 20, 30, 50 is strictly increasing and yield the greatest  sum 110
```
### Space and Time complexity
O(n^2) time | O(n) space - where n is the length of the input array.
