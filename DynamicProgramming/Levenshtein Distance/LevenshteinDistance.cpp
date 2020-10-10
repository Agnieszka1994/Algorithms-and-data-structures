#include <vector>
using namespace std;

int levenshteinDistance(string str1, string str2) {
	vector<vector<int>> numbersOfEdits(str2.length() + 1, vector<int>(str1.length() + 1));

	for (int i = 0; i <= str2.length(); i++) {
		for (int j = 0; j <= str1.length(); j++) {
			numbersOfEdits[i][j] = j;
		}
		numbersOfEdits[i][0] = i;
	}
	for (int i = 1; i <= str2.length(); i++) {
		for (int j = 1; j <= str1.length(); j++) {
			if (str2[i - 1] == str1[j - 1]) {
				numbersOfEdits[i][j] = numbersOfEdits[i - 1][j - 1];
			}
			else
				numbersOfEdits[i][j] =
				min(numbersOfEdits[i - 1][j], min(numbersOfEdits[i - 1][j - 1], numbersOfEdits[i][j - 1])) + 1;
		}
	}
	return numbersOfEdits[str2.length()][str1.length()];
}
