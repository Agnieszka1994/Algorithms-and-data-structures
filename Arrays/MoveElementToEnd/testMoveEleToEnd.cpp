#include "pch.h"
#include "MoveElementToEnd.cpp"
#include <vector>

TEST(SampleTestCase, SampleTest) {
    vector<int> array = { 2, 1, 2, 2, 2, 3, 4, 2 };
    int toMove = 2;
    vector<int> expectedStart = { 1, 3, 4 };
    vector<int> expectedEnd = { 2, 2, 2, 2, 2 };
    vector<int> output = moveElementToEnd(array, toMove);
    assert(output.size() == array.size());
    vector<int> outputStart = vector<int>(output.begin(), output.begin() + 3);
    sort(outputStart.begin(), outputStart.end());
    vector<int> outputEnd = vector<int>(output.begin() + 3, output.end());
    assert(outputStart == expectedStart);
    assert(outputEnd == expectedEnd);
}