# Suffix Trie Construction

This file contains a class `SuffixTrie` for a trie-like data structure. The class has a `root` property set to be the root node of the trie.
The following methods are supported: 
- Creating a `SuffixTrie` from a string - this is done by calling `populateSuffixTrieFrom` method upon class instantiation.
- Searching for strings in the trie.

Every string in the `SuffixTrie` ends with the special `endSymbol` character `"*"`. 

### Sample Input
```javascript
//SuffixTrie Creation:
string = "babc"
//Searching in suffixTrie
string = "abc"

```
### Sample Output
```javascript
//SuffixTrie Creation - the structure below is created
    "a": {"b": {"c": {"*": true}}},
    "b": {"a": {"b": {"c": {"*": true}}}, "c": {"*": true}},
    "c": {"*": true}


true  //SuffixTrie contains the string "abc"

```
### Space and Time complexity
Creation: O(n^2) time | O(n^2) space - where n is the length of the input string. \
Searching: O(m) time | O(1) space - where m is the length of the input string.
