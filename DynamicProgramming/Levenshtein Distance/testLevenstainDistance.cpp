#include "pch.h"
#include "LevenshteinDistance.cpp"

TEST(SampleTestCase1, SampleTest) {
    assert(levenshteinDistance("abc", "yabd") == 2);
};

TEST(SampleTestCase2, SampleTest) {
    assert(levenshteinDistance("abcdefghij", "1234567890") == 10);
};

TEST(SampleTestCase3, SampleTest) {
    assert(levenshteinDistance("table", "bal") == 3);
};