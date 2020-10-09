# SubArray sort

This function takes in a non-empty array of integers and returns an array of the starting and ending indices of the smallest subarray in the input array that needs to be sorted in order for the entire input array to be sorted (in ascending order).

If the input array is already sorted, the function returns [-1, -1]

# Sample input

array = [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]

# Sample output

[3, 9]  //the sub-array from index 3 to index 9 needs to be sorted in order to have the entire array sorted

# Space and Time complexity
O(n) Time | O(1) space 
