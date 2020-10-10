# Levenshtein Distance

This function takes in two strings and returns the minimum number of edit operations that need to be performed on the first string to obtain the second string.

There are three edit operations: insertion of a character, deletion of a character, and substitution of a character for another.

### Sample Input
```javascript
string1 = "abc"
string2 = "yabd"
```
### Sample Output
```javascript
2 // 2 operations need to be performed: insert 'y' and substitute 'c' for 'd'
```
### Space and Time complexity
O(nm) time | O(min(n,m)) space - where n and m are the lengths of the two input strings.
