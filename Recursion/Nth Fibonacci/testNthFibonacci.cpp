#include "pch.h"
#include "NthFibonacci.cpp"

TEST(SampleTestCase1, SampleTest) {
    assert(getNthFib(6) == 5);
};

TEST(SampleTestCase2, SampleTest) {
    assert(getNthFib(13) == 144);
};

TEST(SampleTestCase3, SampleTest) {
    assert(getNthFib(16) == 610);
};