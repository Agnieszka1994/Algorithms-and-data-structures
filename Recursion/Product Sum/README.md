# Product Sum

This function takes in a non-empty array that contains either integers or other arrays and returns its product sum. The product of an array is defined as the sum of its elements, where arrays inside it are summed themselves and then multiplied by their level of depth.

The depth of an array is how far nested it is. For instance - the depth of `[]` is `1`; the depth of the inner array `[[]]` is `2`; the depth of the innermost array in `[[[]]]` is `3`.
Therefore, the product sum of `[x, y]` is `x + y`; and the product sum of `[a, b, [x, y], [z, p]]` is `a + b + 2 * (x + y) + 2 * (z + p)`.

### Sample Input
```javascript
array = [5, 2, [7, -1], 3, [6, [-13, 8], 4]]
```
### Sample Output
```javascript
12 // calculated as: 5 + 2 + 2 * (7 - 1) + 3 + 2 * (6 + 3 * (-13 + 8) + 4)
```
### Space and Time complexity 
O(n) Time | O(d) Space - where n is the number of elements in the array including sub-elements and d is the depth of the input array.