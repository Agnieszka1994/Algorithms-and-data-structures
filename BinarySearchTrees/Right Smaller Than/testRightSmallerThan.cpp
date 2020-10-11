#include "pch.h"
#include "RightSmallerThan.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<int> array = { 8, 5, 11, -1, 3, 4, 2 };
    vector<int> expected{ 5, 4, 4, 0, 1, 1, 0 };
    auto actual = rightSmallerThan(array);
    assert(expected == actual);
};