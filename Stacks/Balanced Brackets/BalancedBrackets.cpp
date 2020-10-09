#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

bool balancedBrackets(string str) {
	unordered_map<char, char> brackets_map{};
	string opening = "{[(";
	string closing = "}])";
	brackets_map.insert(pair<char, char>(')', '('));
	brackets_map.insert(pair<char, char>(']', '['));
	brackets_map.insert(pair<char, char>('}', '{'));

	stack<char> brackets{};

	for (auto sign : str) {
		if (opening.find(sign) != string::npos) {
			brackets.push(sign);
		}
		else if (closing.find(sign) != string::npos) {
			if (brackets.size() == 0) return false;

			if (brackets.top() == brackets_map[sign]) {
				brackets.pop();
			}
			else return false;
		}
		else continue;	 
	}

	if (brackets.empty())
		return true;
	else return false;
}