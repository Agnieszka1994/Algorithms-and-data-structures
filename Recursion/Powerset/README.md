# Powerset

This function takes in an array of unique integers and returns its powerset.
The powerset `P(x)` of a set `x` is the set of all subsets of `x`. For instance, the powerset of `[1, 2]` is `[[], [1], [2], [1, 2]]`.

### Sample Input
```javascript
array = [1, 2, 3]
```
### Sample Output
```javascript
[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
```
### Space and Time complexity 
`O(n*2^n) Time` | `O(n*2^n)` Space - where n is the number of elements in the input array.