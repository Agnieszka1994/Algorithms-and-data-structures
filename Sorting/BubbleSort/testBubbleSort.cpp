#include "pch.h"
#include "BubbleSort.cpp"
#include <queue>

TEST(SampleTestCase, SampleTest) {
    vector<int> expected = { 2, 3, 5, 5, 6, 8, 9 };
    assert(bubbleSort({ 8, 5, 2, 9, 5, 6, 3 }) == expected);
};
