#include "pch.h"
#include "SameBSTs.cpp"

TEST(SampleTestCase_1, SampleTest) {
    vector<int> arrayOne = { 10, 15, 8, 12, 94, 81, 5, 2, 11 };
    vector<int> arrayTwo = { 10, 8, 5, 15, 2, 12, 11, 94, 81 };
    assert(sameBsts(arrayOne, arrayTwo) == true);
};
