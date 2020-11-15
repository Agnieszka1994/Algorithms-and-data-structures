#include "pch.h"
#include "maxProfitWithKTransactions.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<int> input{ 5, 11, 3, 50, 60, 90 };
    assert(maxProfitWithKTransactions(input, 2) == 93);
};