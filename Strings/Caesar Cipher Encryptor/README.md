# Caesar Cipher Encryptor

This function takes in a non-empty string of lowercase letters and non-negative integer `k` representing a key, and returns a new string obtained by shifting every letter in the input string by `k` positions in the alphabet.
The letters wrap around the alphabet (the letter `z` shifted by `1` returns the letter `a`). 

 ### Sample input
```javascript
string = "xyz"
key = 2
```
 ### Sample output
 ```javascript
"zab"
 ```
 ### Space and Time complexity
 O(n) time | O(n) space - where n is the length of the input string.