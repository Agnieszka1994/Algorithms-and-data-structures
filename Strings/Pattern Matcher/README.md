# Pattern Matcher

This function takes two non-empty strings representing a pattern and a normal string, and checks whether the normal strings matches the pattern.
The string pattern consists of only `"x"`s and/or `"y"`s; the normal string consists of alphanumeric characters.

A string `S0` is said to match a pattern if replacing all `"x"`s in the pattern with some non-empty substring `S1` of `S0` and replacing all `"y"` with some non-empty string `S2` of `S0` yelds the same string `S0`.

 ### Sample input 1
```javascript
pattern = "xxyxxy"
string = "gogopowerrangergogopowerranger"
```
 ### Sample output 1
 ```javascript
["go", "powerranger"]
 ```
 ### Sample input 2
```javascript
pattern = "xyxxxyyx"
string = "baddaddoombaddadoomibaddaddoombaddaddoombaddaddoombaddaddoomibaddaddoomibaddaddoom"
```
 ### Sample output 2
 ```javascript
    [] //no pattern found
 ```
 ### Space and Time complexity
 `O(n^2 + m)` time | `O(n + m)` space - where n is the length of the normal string and m is the length of the pattern.