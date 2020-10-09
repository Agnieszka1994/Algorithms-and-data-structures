#include "pch.h"
#include "MonotonicArray.cpp"
#include <vector>

TEST(SampleTestCase, SampleTest) {
    vector<int> input = { -1, -5, -10, -1100, -1100, -1101, -1102, -9001 };
    bool expected = true;
    bool actual = isMonotonic(input);
    assert(expected == actual);
}