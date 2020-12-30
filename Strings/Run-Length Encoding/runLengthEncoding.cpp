#include <iostream>
#include <string>


using namespace std;

string runLengthEncoding(string str) {
    // Write your code here.
    string result{};
    int strLength = str.length();
    int currentCharIdx{};
    int adjacentCharCount{};
    while (currentCharIdx < strLength)
    {
        adjacentCharCount = 1;
        char current_char = str[currentCharIdx];
        currentCharIdx++;
        for (; currentCharIdx < strLength && str[currentCharIdx] == current_char && adjacentCharCount < 9; currentCharIdx++)
        {
            adjacentCharCount++;
        }
        result += to_string(adjacentCharCount) + current_char;

    }

    return result;
}