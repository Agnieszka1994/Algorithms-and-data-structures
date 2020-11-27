#include "pch.h"
#include "patternMatcher.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<string> expected{ "go", "powerranger" };
    assert(patternMatcher("xxyxxy", "gogopowerrangergogopowerranger") ==
        expected);
};