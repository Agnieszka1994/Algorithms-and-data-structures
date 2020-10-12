#include "pch.h"
#include "findThreeLargestNumbers.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<int> expected{ 18, 141, 541 };
    assert(findThreeLargestNumbers(
        { 141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7 }) == expected);
};
