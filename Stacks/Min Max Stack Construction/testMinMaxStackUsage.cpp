#include "pch.h"
#include "MinMaxStackConstruction.cpp"
#define testMinMaxPeek(min, max, peekValue, stack)                             \
  {                                                                            \
    assert(stack.getMin() == min);                                             \
    assert(stack.getMax() == max);                                             \
    assert(stack.peek() == peekValue);                                         \
  }

TEST(SampleTestCase_1, SampleTest) {
    MinMaxStack stack;
    stack.push(5);
    testMinMaxPeek(5, 5, 5, stack);
    stack.push(7);
    testMinMaxPeek(5, 7, 7, stack);
    stack.push(2);
    testMinMaxPeek(2, 7, 2, stack);
    assert(stack.pop() == 2);
    assert(stack.pop() == 7);
    testMinMaxPeek(5, 5, 5, stack);
};
