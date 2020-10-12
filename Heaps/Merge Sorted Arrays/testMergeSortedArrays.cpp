#include "pch.h"
#include "mergeSortedArrays.cpp"
#include <vector>

TEST(SampleTestCase1, SampleTest) {
    vector<vector<int>> arrays = {
          {1, 5, 9, 21},
          {-1, 0},
          {-124, 81, 121},
          {3, 6, 12, 20, 150},
    };
    auto output = mergeSortedArrays(arrays);
    vector<int> expected{ -124, -1, 0,  1,  3,  5,   6,
                         9,    12, 20, 21, 81, 121, 150 };
    assert(output == expected);
};