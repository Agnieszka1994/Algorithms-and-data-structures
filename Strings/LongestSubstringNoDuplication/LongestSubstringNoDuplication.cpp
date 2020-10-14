#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string longestSubstringWithoutDuplication(string str) {
	unordered_map<char, int> lastSeen;
	int startIdx = 0;
	vector<int> longestStr{ 0, 1 };
	for (int i = 0; i < str.length(); i++) {
		if (lastSeen.find(str[i]) != lastSeen.end()) {
			startIdx = max(startIdx, lastSeen[str[i]] + 1);
		}
		if (longestStr[1] - longestStr[0] < i + 1 - startIdx) {
			longestStr = { startIdx, i + 1 };
		}
		lastSeen[str[i]] = i;
	}
	return str.substr(longestStr[0], longestStr[1] - longestStr[0]);
}