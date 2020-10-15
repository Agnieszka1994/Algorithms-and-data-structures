#include "pch.h"
#include "MinNumberOfJumps.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<int> input{ 3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3 };
    assert(minNumberOfJumps(input) == 4);
};