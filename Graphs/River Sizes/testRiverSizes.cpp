#include "pch.h"
#include "RiverSizes.cpp"
#include <vector>

    TEST(SampleTestCase_1, SampleTest) {
        vector<vector<int>> testInput{
        {1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 0},
        };
        vector<int> expected{ 1, 2, 2, 2, 5 };
        vector<int> output = riverSizes(testInput);
        sort(output.begin(), output.end());
        assert(output == expected);
    };

