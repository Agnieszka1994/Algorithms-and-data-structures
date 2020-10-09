#include "pch.h"
#include "FourNumberSum.cpp"
#include <vector>

string sortAndConvertToString(vector<int> array) {
    sort(array.begin(), array.end());
    string s;
    for (int el : array) {
        s += to_string(el);
        s += ",";
    }
    return s;
};

bool isIncluded(vector<string> array, string str1) {
    for (string str2 : array) {
        if (str1 == str2) {
            return true;
        }
    }
    return false;
};

TEST(SampleTestCase, SampleTest) {
    vector<vector<int>> output = fourNumberSum({ 7, 6, 4, -1, 1, 2 }, 16);
    vector<string> output2{};
    for (vector<int> arr : output) {
        output2.push_back(sortAndConvertToString(arr));
    }
    vector<vector<int>> quadruplets{
        {7, 6, 4, -1},
        {7, 6, 1, 2},
    };
    assert(output2.size() == 2);
    for (vector<int> quadruplet : quadruplets) {
        string str1 = sortAndConvertToString(quadruplet);
        bool included = isIncluded(output2, str1);
        assert(included == true);
    }
}

