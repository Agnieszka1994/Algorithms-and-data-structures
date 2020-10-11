#include "pch.h"
#include "interweavingStrings.cpp"

TEST(SampleTestCase1, SampleTest) {
    string one = "aacaaaa";
    string two = "aaabaaa";
    string three = "aaaabacaaaaaaa";
    assert(interweavingStrings(one, two, three) == true);
};

TEST(SampleTestCase2, SampleTest) {
    string one = "aabcc";
    string two = "dbbca";
    string three = "aadbbcbcac";
    assert(interweavingStrings(one, two, three) == true);
};