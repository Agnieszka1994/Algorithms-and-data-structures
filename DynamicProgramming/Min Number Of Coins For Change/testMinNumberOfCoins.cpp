#include "pch.h"
#include "minNumberOfCoinsForChange.cpp"

TEST(SampleTestCase, SampleTest) {
    vector<int> input{ 1, 5, 10 };
    assert(minNumberOfCoinsForChange(7, input) == 3);
};
