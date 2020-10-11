#include "pch.h"
#include "GroupAnagrams.cpp"
bool compare(vector<vector<string>>, vector<vector<string>>);

TEST(SampleTestCase1, SampleTest) {
    vector<string> words = { "yo",  "act", "flop", "tac",
                              "foo", "cat", "oy",   "olfp" };
    vector<vector<string>> expected = {
        {"yo", "oy"}, {"flop", "olfp"}, {"act", "tac", "cat"}, {"foo"} };
    vector<vector<string>> output = groupAnagrams(words);
    for (auto& el : output) {
        sort(el.begin(), el.end());
    }
    assert(compare(expected, output));
};

bool compare(vector<vector<string>> expected, vector<vector<string>> output) {
    if (expected.size() != output.size()) {
        return false;
    }

    for (auto group : expected) {
        sort(group.begin(), group.end());
        if (find(output.begin(), output.end(), group) == output.end()) {
            return false;
        }
    }
    return true;
}