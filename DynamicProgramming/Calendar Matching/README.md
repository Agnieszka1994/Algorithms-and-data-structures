# Calendar Matching

We are given two arrays representing calendars (both of which contain meetings for the day, (in the form of `[startTime, endTime]`), as well as two daily bounds (the earliest and latest availability times), in the form of `[earliestTime, latestTime]`.
This function takes in the above data and the target meeting duration in minutes, and returns a list of all the time blocks (in the form of `[startTime, endTime]`), during which it is possible to schedule the meeting, ordered from earliest time block to latest.

The times are given and returned in military format (`8:30`, `9:02`, `22:55`).


### Sample Input
```javascript
calendar_1 = [["9:00", "10:30"], ["12:00", "13:00"], ["16:00", "18:00"]]
bounds_1 = ["9:00", "20:00"]
calendar_2 = [["10:00", "11:30"], ["12:30", "14:30"], ["14:30", "15:00"], ["16:00", "17:00"]]
bounds_2 = ["10:00", "18:30"]
meetingDuration = 30

```
### Sample Output
```javascript
[["11:30", "12:00"], ["15:00", "16:00"], ["18:00", "18:30"]]
```
### Space and Time complexity
O(c1 + c2) time | O(c1 + c2) space - where c1 and c2 are the respective numbers of meetings in calendar 1 and 2.
