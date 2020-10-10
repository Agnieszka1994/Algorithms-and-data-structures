# Longest Common Subsequence

This function takes in two strings and returns their longest common subsequence.
A subsequence of a string is a set of characters that are not necessarily adjacent in the string, but that are in the same order as they appear in the string.

The characters `["a", "b", "d"]` form a subsequence of the string `"abcd"`, 
and so the characters `["b", "d"]`. A single character and the string itself are both valid subsequences.

### Sample Input
```javascript
string1 = "ZXVVYZW"
string2 = "XKYKZPW"
```
### Sample Output
```javascript
["X", "Y", "Z", "W"]
```
### Space and Time complexity
O(nm) time | O(n,m) space - where n and m are the lengths of the two input strings.
