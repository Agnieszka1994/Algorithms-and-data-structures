# Three number sum

This function takes in a non-empty array of distinct integers and an integer representing a target sum. The function finds all triplets that sum up to the target sum and returns a two-dimentional array of all these triplets.
The numbers in each triplet are sorted in ascending order and the triplets themselves are sorted in ascending order with respect to the numbers they hold.

If there is no three numbers that sum up to the target sum, the function returns an empty array.

### Space and Time complexity

O(n^2) time | O(n) space - where n is the size of the input array.