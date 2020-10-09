#include "pch.h"
#include "SmallestDifference.cpp"
#include <vector>

TEST(SampleTestCase, SampleTest) {
    vector<int> expected{ 28, 26 };
    assert(smallestDifference({ -1, 5, 10, 20, 28, 3 },
        { 26, 134, 135, 15, 17 }) == expected);
}