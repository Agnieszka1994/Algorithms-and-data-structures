#include "pch.h"
#include "BoggleBoard.cpp"

bool contains(vector<string> wordArray, string targetWord) {
    for (string word : wordArray) {
        if (targetWord == word) {
            return true;
        }
    }
    return false;
}

TEST(SampleTestCase_1, SampleTest) {
    vector<vector<char>> board = {
        {'t', 'h', 'i', 's', 'i', 's', 'a'},
        {'s', 'i', 'm', 'p', 'l', 'e', 'x'},
        {'b', 'x', 'x', 'x', 'x', 'e', 'b'},
        {'x', 'o', 'g', 'g', 'l', 'x', 'o'},
        {'x', 'x', 'x', 'D', 'T', 'r', 'a'},
        {'R', 'E', 'P', 'E', 'A', 'd', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'N', 'O', 'T', 'R', 'E', '-', 'P'},
        {'x', 'x', 'D', 'E', 'T', 'A', 'E'},
    };
    vector<string> words = 
    { "this", "is", "not", "a", "simple",   "boggle", "board","test", "REPEATED", "NOTRE-PEATED" };
    vector<string> expected = { "this", "is", "a", "simple", "boggle", "board", "NOTRE-PEATED" };
    vector<string> actual = boggleBoard(board, words);
    assert(actual.size() == expected.size());
    for (string word : actual) {
        assert(contains(expected, word));
    }
};
