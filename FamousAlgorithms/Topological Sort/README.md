# Topological Sort
 This function takes in a list of `jobs` and a list of `dependencies` and returns a list containing a valid order in which the given jobs can be completed. If there is no such order, the function returns an empty array. 

The `jobs` are represented by distinct integers. A `dependency` is represented as a pair of jobs where the first job is a prerequisite of the second job.

 ### Sample Input
```javascript
jobs = [1, 2, 3, 4]
dependencies = [[1, 2], [1, 3], [3, 2], [4, 2], [4, 3]]
```
 ### Sample Output
```javascript
[4, 1, 3, 2]
```
 ### Space and Time complexity
O(j + d) time | O(j + d) space - where j is the number of jobs and d is the number of dependencies.