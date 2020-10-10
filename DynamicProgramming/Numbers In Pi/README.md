# Numbers in PI

This function takes in a string representation of the first n digits of PI and a list of positive integers (all in string format), and returns the smallest number of spaces that can be added to the n digits of PI such that all resulting numbers are found in the list of integers.

If no number of space to be added exists such that all resulting numbers are found in the list of integers, the function returns -1.

### Sample Input
```javascript
PI = "3141592653589793238462643383279"
numbers = [
  "314159265358979323846",
  "26433",
  "8",
  "3279",
  "314159265",
  "35897932384626433832",
  "79"
]
```
### Sample Output
```javascript
2 
// the string can be cut as follows:  314159265 | 35897932384626433832 | 79
// all three numbers are in the input array
```
### Space and Time complexity
O(n^3 + m) time | O(n  + m) space - where n is the number of digits in PI and m is the number of numbers in the input array.
