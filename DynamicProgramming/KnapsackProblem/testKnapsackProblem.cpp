#include "pch.h"
#include "knapsackProblem.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<vector<int>> vector1{ {1, 2}, {4, 3}, {5, 6}, {6, 7} };
    vector<vector<int>> vector1S{ {10}, {1, 3} };
    assert(knapsackProblem(vector1, 10) == vector1S);
};