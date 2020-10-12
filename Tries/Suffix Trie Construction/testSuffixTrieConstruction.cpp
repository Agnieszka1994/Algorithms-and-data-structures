#include "pch.h"
#include "SuffixTrieConstruction.cpp"

TEST(SampleTestCase1, SampleTest) {
    string word1 = "babc";
    SuffixTrie actual(word1);
    assert(actual.contains("abc") == true);
};
TEST(SampleTestCase2, SampleTest) {
    string word1 = "testtest";
    SuffixTrie actual(word1);
    assert(actual.contains("t") == true);
    assert(actual.contains("est") == true);
    assert(actual.contains("ttest") == true);
    assert(actual.contains("sttest") == true);
    assert(actual.contains("esttest") == true);
    assert(actual.contains("tt") == false);
};
