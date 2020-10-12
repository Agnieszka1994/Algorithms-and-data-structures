#include "pch.h"
#include "BinarySearch.cpp"

TEST(SampleTestCase1, SampleTest) {
    assert(binarySearch({ 0, 1, 21, 33, 45, 45, 61, 71, 72, 73 }, 33) == 3);
};
TEST(SampleTestCase2, SampleTest) {
    assert(binarySearch({ 0, 1, 21, 33, 45, 45, 61, 71, 72, 73 }, 73) == 9);
};
TEST(SampleTestCase3, SampleTest) {
    assert(binarySearch({ 5, 23, 111 }, 3) == -1);
};