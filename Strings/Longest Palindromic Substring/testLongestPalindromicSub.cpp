#include "pch.h"
#include "LongestPalindromicSubstring.cpp"

TEST(SampleTestCase1, SampleTest) {
    assert(longestPalindromicSubstring("abaxyzzyxf") == "xyzzyx");
};

TEST(SampleTestCase2, SampleTest) {
    assert(longestPalindromicSubstring("zzzzzzz2345abbbba5432zzbbababa") == "zz2345abbbba5432zz");
};