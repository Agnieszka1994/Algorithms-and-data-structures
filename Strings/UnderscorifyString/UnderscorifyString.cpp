#include <numeric>
using namespace std;
vector<vector<int>> getPos(string str, string substr);
vector<vector<int>> eraseOverlapping(vector<vector<int>> positions);
string addUnderscores(string str, vector<vector<int>> positions);

string underscorifySubstring(string str, string subStr) {
	vector<vector<int>> solution = eraseOverlapping(getPos(str, subStr));
	return addUnderscores(str, solution);
}

vector<vector<int>> getPos(string str, string substr)
{
	vector<vector<int>> positions{};
	int startIdx{ 0 };
	while (startIdx < str.length()) {
		int nextIdx = str.find(substr, startIdx);
		if (nextIdx != string::npos) {
			positions.push_back(vector<int>{nextIdx, int(nextIdx + substr.length())});
			startIdx = nextIdx + 1;
		}
		else {
			break;
		}
	}
	return positions;
}

vector<vector<int>> eraseOverlapping(vector<vector<int>> positions) {
	if (positions.empty()) {
		return positions;
	}

	vector<vector<int>> newPositions{ positions.front() };
	vector<int>* prev = &(newPositions.front());
	for (auto& position : positions) {
		vector<int>* current = &position;
		if (current->at(0) <= prev->at(1)) {
			prev->at(1) = current->at(1);
		}
		else {
			newPositions.push_back(*current);
			prev = &(newPositions[newPositions.size() - 1]);
		}
	}
	return newPositions;
}

string addUnderscores(string str, vector<vector<int>> positions) {
	int posIdx{ 0 };
	int strIdx{ 0 };
	bool betweenUnderscores = false;
	vector<string> solution{};
	int i{ 0 };
	while (strIdx < str.length() && posIdx < positions.size()) {
		if (strIdx == positions[posIdx][i]) {
			solution.push_back("_");
			betweenUnderscores = !betweenUnderscores;
			if (!betweenUnderscores) {
				posIdx++;
			}
			i = i == 1 ? 0 : 1;
		}
		string helper(1, str[strIdx]);
		solution.push_back(helper);
		strIdx++;
	}
	if (posIdx < positions.size()) {
		solution.push_back("_");
	}
	else if (strIdx < str.length()) {
		solution.push_back(str.substr(strIdx));
	}
	return accumulate(solution.begin(), solution.end(), string());
}