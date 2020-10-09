# Min Max Stack Construction
This file contains a class `MinMaxStack`.
The class suppotrs:
- Pushing and popping valueas on and off the stack.
- Peeking at the value at the top of the stack.
- Getting both the minimum and the maximum values in the stack at any given point in time.

### Sample Usage and expected output
```javascript
//Operations performed sequentially.
MinMaxStack(): - //instantiate a MinMaxStack
push(5): -
getMin(): 5
getMax(): 5
peek(): 5
push(7): -
getMin(): 5
getMax(): 7
peek(): 7
push(2): -
getMin(): 2
getMax(): 7
peek(): 2
pop(): 2
pop(): 7
getMin(): 5
getMax(): 5
peek(): 5
```

### Space and Time complexity

O(1) Space | O(1) Time 