# Min Heap Construction

This file contains a `MinHeap` class that supports:
 - Building a `MinHeap` from an input array of integers.
 - Inserting Integers in the heap.
 - Removing the heap's minimum/root value.
 - Peeking at the heap's minimum/root value.
 - Sifting integers up and down the heap, which is to be used when inserting and removing values.

 The heap is represented in the form of an array.

### Sample Usage
```javascript
inputArray = [48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41]

//all below operations are performed sequentially
MinHeap(inputArray): //minHeap is instantiated calling buildHeap method
insert(76): // [-5, 2, 6, 7, 8, 8, 24, 391, 24, 56, 12, 24, 48, 41, 76]
peek(): -5
remove(): -5 // [2, 7, 6, 24, 8, 8, 24, 391, 76, 56, 12, 24, 48, 41]
peek(): 2
remove(): 2  // [6, 7, 8, 24, 8, 24, 24, 391, 76, 56, 12, 41, 48]
peek(): 6
insert(87):  // [6, 7, 8, 24, 8, 24, 24, 391, 76, 56, 12, 41, 48, 87]
```
### Space and Time complexity
`SiftDown`, `ShiftUp`, `Remove` & `Insert`: \
O(log(n)) time | O(1) space - where n is the length of the heap. \
`BuildHeap` : \
O(n) time | O(1) space - where n is the length of the input array. \
`Peek`: \
O(1) time | O(1) space