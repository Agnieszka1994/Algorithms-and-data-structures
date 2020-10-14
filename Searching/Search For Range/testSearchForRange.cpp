#include "pch.h"
#include "SearchForRange.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<int> expected{ 4, 9 };
    assert(searchForRange({ 0, 1, 21, 33, 45, 45, 45, 45, 45, 45, 61, 71, 73 },
        45) == expected);
};