# Multi String Search

This function takes in a big string and an array of small strings and returns an array of booleans, where each boolean represents whether the small string at that index in the array of small strings is contained in the big string.
The function uses `SuffixTrie` class to solve this problem.
### Sample Input
```javascript

bigString = "this is a big string"
smallStrings = ["this", "yo", "is", "a", "bigger", "string", "kappa"]

```
### Sample Output
```javascript
[true, false, true, true, false, true, false]
```
### Space and Time complexity
O(ns + bs) time | O(ns) space - where n is the number of small strings, s is the length of the longest small string and b is the length of the big string.