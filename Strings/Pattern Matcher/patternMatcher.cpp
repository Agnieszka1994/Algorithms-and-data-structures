#include <numeric>
#include <vector>
using namespace std;

vector<char> getNewPattern(string pattern);

int getYPosition(vector<char>, unordered_map<char, int>* counts);

vector<string> patternMatcher(string pattern, string str) {
	if (pattern.length() > str.length()) {
		return {};
	}

	vector<char> newPattern{ getNewPattern(pattern) };

	bool didSwitch = newPattern.at(0) != pattern.at(0);

	unordered_map<char, int> counts{ {'x', 0 }, { 'y', 0 } };
	int firstYPosition{ getYPosition(newPattern, &counts) };

	if (counts.at('y') != 0) {
		for (int lenOfX = 1; lenOfX < str.length(); lenOfX++) {
			double lenOfY =
				(static_cast<double>(str.length()) - static_cast<double>(lenOfX)
					* static_cast<double>(counts.at('x'))) / static_cast<double>(counts.at('y'));
			if (lenOfY <= 0 || fmod(lenOfY, 1) != 0) {
				continue;
			}
			int yIdx{ firstYPosition * lenOfX };
			string x{ str.substr(0, lenOfX) };
			string y{ str.substr(yIdx, lenOfY) };

			vector<string> potentialMatch{ newPattern.size(), "" };
			transform(newPattern.begin(), newPattern.end(), potentialMatch.begin(),
				[x, y](char c) { return c == 'x' ? x : y; });
			if (str == accumulate(potentialMatch.begin(), potentialMatch.end(), string{ "" })) {
				return !didSwitch ? vector<string>{x, y} : vector<string>{ y, x };
			}
		}
	}
	else {
		double lenOfX{ static_cast<double>(str.length() / counts.at('x')) };
		if (fmod(lenOfX, 1) == 0) {
			string x{ str.substr(0, lenOfX) };
			vector<string> potentialMatch{ newPattern.size(), "" };
			transform(newPattern.begin(), newPattern.end(), potentialMatch.begin(),
				[x](char c) { return x; });
			if (str == accumulate(potentialMatch.begin(), potentialMatch.end(), string{ "" })) {
				return !didSwitch ? vector<string>{x, ""} : vector<string>{ "", x };
			}
		}
	}
	return {};
}

vector<char> getNewPattern(string pattern) {
	vector<char> letters(pattern.begin(), pattern.end());
	if (pattern.at(0) == 'x') {
		return letters;
	}
	else {
		transform(letters.begin(), letters.end(), letters.begin(),
			[](char c) {return c == 'y' ? 'x' : 'y'; });
		return letters;
	}
}

int getYPosition(vector<char> pattern, unordered_map<char, int>* counts) {

	int firstYPosition{ -1 };
	for (int i = 0; i < pattern.size(); i++) {
		char c = pattern.at(i);
		counts->at(c)++;
		if (c == 'y' && firstYPosition == -1) {
			firstYPosition = i;
		}
	}
	return firstYPosition;
}