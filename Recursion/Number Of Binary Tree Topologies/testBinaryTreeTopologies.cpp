#include "pch.h"
#include "BinaryTreeTopologies.cpp"

TEST(SampleTestCase1, SampleTest) {
    assert(numberOfBinaryTreeTopologies(3) == 5);
};

TEST(SampleTestCase2, SampleTest) {
    assert(numberOfBinaryTreeTopologies(6) == 132);
};

TEST(SampleTestCase3, SampleTest) {
    assert(numberOfBinaryTreeTopologies(7) == 429);
};

TEST(SampleTestCase4, SampleTest) {
    assert(numberOfBinaryTreeTopologies(9) == 4862);
};

TEST(SampleTestCase5, SampleTest) {
    assert(numberOfBinaryTreeTopologies(0) == 1);
};

TEST(SampleTestCase6, SampleTest) {
    assert(numberOfBinaryTreeTopologies(10) == 16796);
};