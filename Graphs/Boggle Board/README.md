# Boggle Board

This function takes in a two-dimentional array of letters (boggle board) and a list of words, and returns an array of all the words contained in the boggle board.

 A word is constructed in the boggle board by connecting adjacent letters (horizontally, vertically, or diagonally) without using any single letter at a given position more than once.
 Two or more words are allowed to overlap and use the same letters in the boggle board. 

 ### Sample input
```javascript
board = [
  ["t", "h", "i", "s", "i", "s", "a"],
  ["s", "i", "m", "p", "l", "e", "x"],
  ["b", "x", "x", "x", "x", "e", "b"],
  ["x", "o", "g", "g", "l", "x", "o"],
  ["x", "x", "x", "D", "T", "r", "a"],
  ["R", "E", "P", "E", "A", "d", "x"],
  ["x", "x", "x", "x", "x", "x", "x"],
  ["N", "O", "T", "R", "E", "-", "P"],
  ["x", "x", "D", "E", "T", "A", "E"]
]
words = ["this", "is", "not", "a", "simple", "boggle",
        "board", "test", "REPEATED", "NOTRE-PEATED"]
```
 ### Sample output
 ```javascript
["this", "is", "a", "simple", "boggle", "board", "NOTRE-PEATED"]
 ```
 ### Space and Time complexity
 O(nm*8^s + ws) time | O(nm + ws) space - where n is the width of the board, m is the height of the board, w is the number of words and s is the length of the longest word.