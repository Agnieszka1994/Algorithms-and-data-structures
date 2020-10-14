#include "pch.h"
#include "Quickselect.cpp"

TEST(SampleTestCase1, SampleTest) {
    assert(quickselect({ 8, 5, 2, 9, 7, 6, 3 }, 3) == 5);
};