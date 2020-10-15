#include "pch.h"
#include "largestRange.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<int> expected{ 0, 7 };
    assert(largestRange({ 1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6 }) ==
        expected);
};