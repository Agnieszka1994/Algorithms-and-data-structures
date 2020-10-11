#include "pch.h"
#include "PalindromeCheck.cpp"

TEST(SampleTestCase1, SampleTest) {
    assert(isPalindrome("abcdcba"));
};

TEST(SampleTestCase2, SampleTest) {
    assert(isPalindrome("abcdefghhgfedcba"));
};