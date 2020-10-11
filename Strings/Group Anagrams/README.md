# Group Anagrams

This function takes in an array of strings and groups anagrams together.
Anagrams are strictly made up of exactly the same letters, where order doesn't matter. For instance, `"foo"` and `"ofo"` are anagrams. 

 ### Sample input
```javascript
strings = ["yo", "aag", "act", "flop", "tac", "foo", "cat", "aga", "oy", "olfp", "gaa"]
```
 ### Sample output
 ```javascript
[["foo"], ["yo", "oy"], ["flop", "olfp"], ["act", "tac", "cat"], ["gaa", "aga", "aag"]]
 ```
 ### Space and Time complexity
 `O(w*n*log(n))` time | `O(wn)` space - where w is the number of words and n is the length of the longest word.