#include "pch.h"
#include "squareOfZeroes.cpp"
#include <unordered_map>

TEST(SampleTestCase, SampleTest) {
    vector<vector<int>> input = {
        {1, 1, 1, 0, 1, 0}, 
        {0, 0, 0, 0, 0, 1}, 
        {0, 1, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 1}, 
        {0, 1, 1, 1, 0, 1}, 
        {0, 0, 0, 0, 0, 1},
    };
    assert(squareOfZeroes(input));
};
