#include "pch.h"
#include "UnderscorifyString.cpp"

TEST(SampleTestCase1, SampleTest) {
    assert(
        underscorifySubstring(
            "testthis is a testtest to see if testestest it works", "test") ==
        "_test_this is a _testtest_ to see if _testestest_ it works");
};