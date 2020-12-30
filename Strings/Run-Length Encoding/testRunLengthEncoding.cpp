#include "pch.h"
#include "runLengthEncoding.cpp"

TEST(SampleTestCase1, SampleTest) {
    auto input = "AAAAAAAAAAAAABBCCCCDD";
    auto expected = "9A4A2B4C2D";
    auto actual = runLengthEncoding(input);
    assert(expected == actual);
};