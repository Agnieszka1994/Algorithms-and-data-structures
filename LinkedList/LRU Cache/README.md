# LRU Cache
This file contains a class LRUCache (Last Recently Used). 
The class support:\
- inserting key-value pairs with the **insertKeyValuePair** method.\
- retrieving a key's value with the **getValueFromKey** method.\
- retrieving the most recently used (inserted or retrieved) key with the **getMostRecentKey** method.
Each of those methods run in constant time.\


Additionally LRUCache class stores maxSize property set to the size of the cache, which is passed in as an argument during instantiation.\


Inserting a key-value pair with an already existing key replaces the key's value in the cache with the new value.\
Retrieving a value from a key that is not in the cache returns **nullptr**.


### Sample Usage


**LRUCache(3)** - instantiate an LRU Cache of size 3\
**insertKeyValuePair("a", 99):** -\
**insertKeyValuePair("b", 100):** -\
**insertKeyValuePair("c", 101):** -\
**getMostRecentKey():** - returns "c", as it was the most recently inserted\
**getValueFromKey("a"):** - returns 99\
**getMostRecentKey():** - returns "a", as it was the most recently retrieved\
**insertKeyValuePair("d", 102):** - cache had 3 entries - the last recently used is evicted\
**getValueFromKey("b"):** - returns **nullptr** ("b" was removed in the previous operation)\
**insertKeyValuePair("a", 95):** - "a" exists in the cache so its value is replaced


### Space and Time complexity
O(1) time | O(1) space\