#include "pch.h"
#include "CaesarCipherEncryptor.cpp"
 
TEST(SampleTestCase1, SampleTest) {
    assert(caesarCypherEncryptor("xyz", 2) == "zab");
};

TEST(SampleTestCase2, SampleTest) {
    assert(caesarCypherEncryptor("mvklahvjcnbwqvtutmfafkwiuagjkzmzwgf", 7)
        == "tcrshocqjuidxcabatmhmrdpbhnqrgtgdnm");
};

TEST(SampleTestCase3, SampleTest) {
    assert(caesarCypherEncryptor("kjwmntauvjjnmsagwgawkagfuaugjhawgnawgjhawjgawbfawghesh", 15) 
        == "zylbcipjkyycbhpvlvplzpvujpjvywplvcplvywplyvplquplvwthw");
};

TEST(SampleTestCase4, SampleTest) {
    assert(caesarCypherEncryptor("abc", 57) == "fgh");
};

TEST(SampleTestCase5, SampleTest) {
    assert(caesarCypherEncryptor("xyz", 25) == "wxy");
};