#include "pch.h"
#include "diskStacking.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<vector<int>> input{ {2, 1, 2}, {3, 2, 3}, {2, 2, 8},
                                {2, 3, 4}, {2, 2, 1}, {4, 4, 5} };
    vector<vector<int>> expected{ {2, 1, 2}, {3, 2, 3}, {4, 4, 5} };
    assert(diskStacking(input) == expected);
};