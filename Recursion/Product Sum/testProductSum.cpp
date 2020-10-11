#include "pch.h"
#include "ProductSum.cpp"
#include <any>

TEST(SampleTestCase1, SampleTest) {
    vector<any> test = { 5, 2, vector<any>{7, -1}, 3,
                          vector<any>{6, vector<any>{-13, 8}, 4} };
    assert(productSum(test) == 12);
};