#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
	vector<vector<string>> solution{};
	string sorted;
	unordered_map<string, vector<string> > sortedWords;

	for (auto word : words) {
		sorted = word;
		sort(sorted.begin(), sorted.end());
		auto get = sortedWords.find(sorted);
		if (get == sortedWords.end()) {
			sortedWords.insert({ sorted , vector<string>{word} });
		}
		else {
			sortedWords[sorted].push_back(word);
		}
	}
	for (auto sortedWords : sortedWords) {
		solution.push_back(sortedWords.second);
		}
	return solution;
}