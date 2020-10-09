# Longest Peak

This function takes in an array of integers and returns the length of the longest peak in the array.
A peak is defined as adjacent integers that are **strictly increasing** until they reach the highest value in the peak (a tip) at which point they become **strictly decreasing**.
At least 3 integers are required to form a peak.

# Sample input

array = [1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3]

# Sample output

6 

(longest peak -> [0, 10, 6, 5, -1, -3]) 

# Space and Time complexity
O(n) Time | O(1) space 
