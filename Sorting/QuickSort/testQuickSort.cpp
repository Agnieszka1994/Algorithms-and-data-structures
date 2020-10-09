#include "pch.h"
#include "QuickSort.cpp"

TEST(SampleTestCase, SampleTest) {
    vector<int> expected = { 2, 3, 5, 5, 6, 8, 9 };
    assert(quickSort({ 8, 5, 2, 9, 5, 6, 3 }) == expected);
};
