#include <vector>
using namespace std;

vector<int> buildPattern(string);
bool doesMatch(string, string, vector<int>);

bool knuthMorrisPrattAlgorithm(string str, string substr) {
	vector<int> pattern = buildPattern(substr);
	return doesMatch(str, substr, pattern);
}

vector<int> buildPattern(string substring) {
	vector<int> pattern(substring.size(), -1);
	int i{ 1 };
	int j{ 0 };

	while (i < substring.size()) {
		if (substring[i] == substring[j]) {
			pattern[i] = j;
			i++;
			j++;
		}
		else if (j > 0) {
			j = pattern[j - 1] + 1;
		}
		else {
			i++;
		}
	}
	return pattern;
}

bool doesMatch(string str, string substring, vector<int> pattern) {
	int i{ 0 };
	int j{ 0 };
	while (i + substring.size() - j <= str.size()) {
		if (str[i] == substring[j]) {
			if (j == substring.size() - 1)
				return true;
			i++;
			j++;
		}
		else if (j > 0) {
			j = pattern[j - 1] + 1;
		}
		else {
			i++;
		}
	}
	return false;
}