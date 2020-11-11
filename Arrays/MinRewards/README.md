# Min Rewards

We are given a list of student scores on the final examin a particular order. The task is to reward the students according to the following rules:
- all students must receive at least one reward
- any given student must receive strictly more rewards than an adjacent student with a lower score.

This function takes in an array of scores and returns the minimum number of rewards that must be given out to the students to satisfy the two rules.

If no four numbers sum up to the target sum, the function returns an empty array.
The scores are all unique!

# Sample input
```javascript
array = [8, 4, 2, 1, 3, 6, 7, 9, 5]
```

# Sample output
```
25 // the following rewards will be given [4, 3, 2, 1, 2, 3, 4, 5, 1]
```
# Space and Time complexity
O(n) time | O(n) space - where n is the length of the input array