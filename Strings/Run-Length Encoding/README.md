# Run-Length Encoding

This function takes in a non-empty string and returns its run-length encoding.
Run-length encoding is a form of lossless data compression in which runs of data are stored as a single data value and count, rather than as the original run. So the run `"AAA"` would be run-length-encoded as `"3A"`. Runs of `10 or more` characters should be encoded in a split fashion; the run `"AAAAAAAAAAAA"` shoould be ebcoded as  `"9A3A"`, (not "12A").

 ### Sample input
```javascript
"AAAAAAAAAAAAABBCCCCDD"
```
 ### Sample output
 ```javascript
"9A4A2B4C2D"
 ```
 ### Space and Time complexity
 `O(n)` time | `O(n)` space - where n is the length of the input string.