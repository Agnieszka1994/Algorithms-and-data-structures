#include "pch.h"
#include "maxSubsetSumNoAdjacent.cpp"

TEST(SampleTestCase, SampleTest) {
    vector<int> vector{ 75, 105, 120, 75, 90, 135 };
    assert(maxSubsetSumNoAdjacent(vector) == 330);
};
