#include "pch.h"
#include "kadanesAlgorithm.cpp"

TEST(SampleTestCase1, SampleTest) {
    assert(kadanesAlgorithm(
        { 3, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4 }) == 19);
};