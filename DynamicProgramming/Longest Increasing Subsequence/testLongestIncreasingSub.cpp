#include "pch.h"
#include "longestIncreasingSubsequence.cpp"

TEST(SampleTestCase, SampleTest) {
    vector<int> expected{ -24, 2, 3, 5, 6, 35 };
    vector<int> input{ 5, 7, -24, 12, 10, 2, 3, 12, 5, 6, 35 };
    assert(longestIncreasingSubsequence(input) == expected);
};
