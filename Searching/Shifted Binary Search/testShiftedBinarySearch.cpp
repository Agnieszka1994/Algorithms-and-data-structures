#include "pch.h"
#include "shiftedBinarySearch.cpp"

TEST(SampleTestCase1, SampleTest) {
    assert(shiftedBinarySearch({ 45, 61, 71, 72, 73, 0, 1, 21, 33, 37 }, 33) ==
        8);
};
TEST(SampleTestCase2, SampleTest) {
    assert(shiftedBinarySearch({ 61, 71, 72, 73, 0, 1, 21, 33, 37, 45 }, 33) ==
        7);
};
TEST(TestThatFails, SampleTest) {
    EXPECT_EQ(shiftedBinarySearch({ 72, 73, 0, 1, 21, 33, 37, 45, 61, 71 }, 72),
        8);
};
TEST(SampleTestCase4, SampleTest) {
    assert(shiftedBinarySearch({ 73, 0, 1, 21, 33, 37, 45, 61, 71, 72 }, 70) ==
        -1);
};
TEST(SampleTestCase5, SampleTest) {
    assert(shiftedBinarySearch({ 45, 61, 71, 72, 73, 0, 1, 21, 33, 37 }, 0) ==
        5);
};
TEST(SampleTestCase6, SampleTest) {
    assert(shiftedBinarySearch({ 0, 1, 21, 33, 37, 45, 61, 71, 72, 73 }, 73) ==
        9);
};