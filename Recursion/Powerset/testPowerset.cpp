#include "pch.h"
#include "Powerset.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<vector<int>> output = powerset({ 1, 2, 3 });
    for (int i = 0; i < output.size(); i++) {
        sort(output[i].begin(), output[i].end());
    }
    assert(output.size() == 8);
    vector<vector<int>>::iterator it =
        find(output.begin(), output.end(), vector<int>{});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{1});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{2});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{3});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{1, 2});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{1, 3});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{2, 3});
    assert(it != output.end());
    it = find(output.begin(), output.end(), vector<int>{1, 2, 3});
    assert(it != output.end());
};