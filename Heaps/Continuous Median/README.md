# Continuous Median

This file contains a `ContinuousMedianHandler` class that supports:
- The continuous insertion of numbers with the `insert` method. 
- The instant O(1) retrieval of the median of the numbers with `getMedian` method.

The median of a set of numbers is the `middle` number when the numbers are ordered from smallest to greatest. If there is an odd number of numbers in the set, as in `[1, 3, 7]`, the median is the number in the middle (`3`). If there is an even number of numbers in the set, as in `[1, 3, 7, 8]`, the median is the average of the two middle numbers (`(3 + 7)/2 = 5`).

### Sample Usage
```javascript
ContinuousMedianHandler():
insert(5): - 
insert(10): - 
getMedian(): 7.5
insert(100): -
getMedian(): 10
```
### Space and Time complexity
Insert: `O(log(n))` time |`O(n)` space - where n is the number of inserted numbers.