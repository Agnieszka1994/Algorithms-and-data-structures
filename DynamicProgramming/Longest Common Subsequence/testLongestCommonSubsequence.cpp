#include "pch.h"
#include "longestCommonSubsequence.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<char> expected{ 'X', 'Y', 'Z', 'W' };
    assert(longestCommonSubsequence("ZXVVYZW", "XKYKZPW") == expected);
};

TEST(SampleTestCase2, SampleTest) {
    vector<char> expected{ 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    assert(longestCommonSubsequence("ABCDEFG", "ABCDEFG") == expected);
};

TEST(SampleTestCase3, SampleTest) {
    vector<char> expected{ 'A', 'E' };
    assert(longestCommonSubsequence("ABCDEFG", "APPLES") == expected);
};

TEST(SampleTestCase4, SampleTest) {
    vector<char> expected{ '8', '4', '2' };
    assert(longestCommonSubsequence("8111111111111111142", "222222222822222222222222222222433333333332") == expected);
};

TEST(SampleTestCase5, SampleTest) {
    vector<char> expected{ 'C', 'D', 'E', 'G', 'H', 'J', 'K', 'L', 'T', 'U', 'V' };
    assert(longestCommonSubsequence("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "CCCDDEGDHAGKGLWAJWKJAWGKGWJAKLGGWAFWLFFWAGJWKAGTUV") == expected);
};
