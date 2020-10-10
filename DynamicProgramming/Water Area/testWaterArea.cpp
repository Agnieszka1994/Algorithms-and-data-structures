#include "pch.h"
#include "waterArea.cpp"

TEST(SampleTestCase, SampleTest) {
    vector<int> input{ 0, 8, 0, 0, 5, 0, 0, 10, 0, 0, 1, 1, 0, 3 };
    assert(waterArea(input) == 48);
};
