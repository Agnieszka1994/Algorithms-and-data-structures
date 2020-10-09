#include "pch.h"
#include "BalancedBrackets.cpp"

TEST(SampleTestCase_1, SampleTest) {
    assert(balancedBrackets("([])(){}(())()()") == true);
};

TEST(SampleTestCase_2, SampleTest) {
    assert(balancedBrackets("([}])(){}(())()()") == false);
};
