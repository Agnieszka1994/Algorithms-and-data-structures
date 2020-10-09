#include "pch.h"
#include "SubarraySort.cpp"
#include <vector>

TEST(SampleTestCase, SampleTest) {
    vector<int> expected{ 3, 9 };
    assert(subarraySort({ 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19 }) ==
        expected);
}

