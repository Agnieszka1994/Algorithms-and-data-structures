#include <vector>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
	vector < vector< vector <char>>> longestCommon;
	
	for (int i = 0; i < str2.length() + 1; i++) {
		longestCommon.push_back(vector< vector <char>>());
		for (int j = 0; j < str1.length() +1; j++) {
			longestCommon[i].push_back(vector <char>());
		}
	}
	for (int i = 1; i < str2.length() + 1; i++) {
		for (int j = 1; j < str1.length() +1; j++) {
			if(str2[i-1] == str1[j-1]){
				vector <char> copy = longestCommon[i-1][j-1];
				copy.push_back(str2[i-1]);
				longestCommon[i][j] = copy;
			}else{
				longestCommon[i][j] = longestCommon[i-1][j].size() > longestCommon[i][j-1].size() ? 
					longestCommon[i-1][j]: longestCommon[i][j-1]; 
			}
		}
	}
	return longestCommon[str2.length()][str1.length()];
}