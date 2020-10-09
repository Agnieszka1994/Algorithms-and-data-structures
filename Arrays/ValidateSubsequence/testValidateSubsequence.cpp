#include "pch.h"
#include "ValidateSubsequence.cpp"
#include <vector>

TEST(SampleTestCase, SampleTest) {
    vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
    vector<int> sequence = { 1, 6, -1, 10 };
    assert(isValidSubsequence(array, sequence));
}