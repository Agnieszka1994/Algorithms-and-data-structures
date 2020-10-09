#include "pch.h"
#include "TwoNumberSum.cpp"
#include <vector>

TEST(SampleTestCase, SampleTest) {
    vector<int> output = twoNumberSum({ 3, 5, -4, 8, 11, 1, -1, 6 }, 10);
    EXPECT_EQ(output.size(),2);
    assert(count(output.begin(), output.end(), -1));
    assert(count(output.begin(), output.end(), 11));
}