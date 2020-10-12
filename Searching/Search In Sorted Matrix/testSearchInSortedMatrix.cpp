#include "pch.h"
#include "searchInSortedMatrix.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<vector<int>> matrix{
        {1, 4, 7, 12, 15, 1000},        
        {2, 5, 19, 31, 32, 1001},
        {3, 8, 24, 33, 35, 1002},       
        {40, 41, 42, 44, 45, 1003},
        {99, 100, 103, 106, 128, 1004},
    };
    vector<int> expected{ 3, 3 };
    assert(searchInSortedMatrix(matrix, 44) == expected);
};