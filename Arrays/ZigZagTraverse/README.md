# ZigZag Traverse

This function takes in a two-dimentional array that can be either rectangle-shaped or square-shaped and returns a one-dimentional array of all the array's elements in zigzag order. 
Zigzag starts at the top left corner of the two-dimentional array, goes down by one element and proceeds in a zigzag pattern all the way to the bottom right corner

### Sample input
array = [ \
    [1,  3,  4, 10],\
    [2,  5,  9, 11],\
    [6,  8, 12, 15],\
    [7, 13, 14, 16],\
]
### Sample output

[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]

### Space and Time complexity
O(n) Time | O(n) Space - where n is the total number of elements in the array.