# Underscorify Substring

This function takes in two strings: a main string and a potential substring of the main string; and returns a version of the main string with every instance of the substring in it wrapped between underscores.
If two or more instance of the substring overlap each other or sit side by side, the underscores appear on the far left of the leftmost substring and on the far right of the rightmost substring.

 ### Sample input
```javascript
string = "testthis is a testtest to see if testestest it works"
substring = "test"
```
 ### Sample output
 ```javascript
"_test_this is a _testtest_ to see if _testestest_ it works"
 ```
 ### Sample input 2
```javascript
string = "abababababababababababababaababaaabbababaa"
substring = "a"
```
 ### Sample output 2
 ```javascript
"_a_b_a_b_a_b_a_b_a_b_a_b_a_b_a_b_a_b_a_b_a_b_a_b_a_b_aa_b_a_b_aaa_bb_a_b_a_b_aa_"
 ```
 ### Space and Time complexity
 `O(n +m)` time | `O(n)` space - where n is the length of the main string and m is the length of the substring.