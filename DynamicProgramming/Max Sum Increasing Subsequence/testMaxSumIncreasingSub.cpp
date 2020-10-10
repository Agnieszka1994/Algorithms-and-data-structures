#include "pch.h"
#include "maxSumIncreasingSubsequence.cpp"

TEST(SampleTestCase, SampleTest) {
    vector<int> input{ 10, 70, 20, 30, 50, 11, 30 };
    vector<vector<int>> expected{ {110}, {10, 20, 30, 50} };
    assert(maxSumIncreasingSubsequence(input) == expected);
};
