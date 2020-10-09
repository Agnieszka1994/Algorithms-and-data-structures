#include "pch.h"
#include "LongestPeak.cpp"
#include <vector>

TEST(SampleTestCase, SampleTest) {
    vector<int> input = { 1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3 };
    int expected = 6;
    int actual = longestPeak(input);
    assert(expected == actual);
}