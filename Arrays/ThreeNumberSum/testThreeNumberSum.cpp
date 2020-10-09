#include "pch.h"
#include "ThreeNumberSum.cpp"
#include <vector>

TEST(SampleTestCase, SampleTest) {
    vector<vector<int>> expected{ {-8, 2, 6}, {-8, 3, 5}, {-6, 1, 5} };
    assert(threeNumberSum({ 12, 3, 1, 2, -6, 5, -8, 6 }, 0) == expected);
}