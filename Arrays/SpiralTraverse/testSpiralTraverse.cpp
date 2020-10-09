#include "pch.h"
#include "SpiralTraverse.cpp"
#include <vector>

TEST(SampleTestCase, SampleTest) {
    vector<vector<int>> input = {
          {1, 2, 3, 4},
          {12, 13, 14, 5},
          {11, 16, 15, 6},
          {10, 9, 8, 7},
    };
    vector<int> expected = { 1, 2,  3,  4,  5,  6,  7,  8,
                            9, 10, 11, 12, 13, 14, 15, 16 };
    vector<int> actual = spiralTraverse(input);
    assert(expected == actual);
}