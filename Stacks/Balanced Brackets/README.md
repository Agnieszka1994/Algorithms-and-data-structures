# Balanced Brackets

This function takes in a string made up of brackets ( `(`, `[`, `{`, `}`, `]`, and `)`) and other optional characters. The function returns a boolean representing whether the string is balanced with regards to brackets (if it has as many opening brackets of a certain type as it has closing brackets of that type and if no bracket is unmatched). An opening bracket cannot match a corresponding closing bracket that comes before it and otherwise. Also, brackets cannot overlap each other as in `[(])`.

### Sample input

```javascript
string = "([])(){}(())()()"
```
### Sample output
```javascript
true // it's balanced
```
### Space and Time complexity

O(n) Time | O(n) Space - where n is the length of the input array. 