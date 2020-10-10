# Water Area

This function takes in an array of non-negative integers where each non-zero integer represents the height of a pillar of width `1`. Let's imagine water being poured over all of the pillars. The function returns the surface area of water trapped between the pillars viewed from the front.

### Sample Input
```javascript
pillars = [0, 8, 0, 0, 5, 0, 0, 10, 0, 0, 1, 1, 0, 3]
/* below visual representation: 
  
        |
        |
  |.....|
  |.....|
  |.....|
  |..|..|
  |..|..|
  |..|..|.....|
  |..|..|.....|
 _|..|..|..||.|
```
### Sample Output
```javascript
48

/* there are 48 dots = water units trapped between the pillars (lines): 
  
        |
        |
  |.....|
  |.....|
  |.....|
  |..|..|
  |..|..|
  |..|..|.....|
  |..|..|.....|
 _|..|..|..||.|

```
### Space and Time complexity
O(n) time | O(1) space - where n is the length of the input array.
