#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {

	unordered_map<int, vector<vector<int>>> hashTable;
	vector<vector<int>> solution;

	for (int i = 1; i < array.size() - 1; i++) {
		for (int j = i + 1; j < array.size(); j++) {
			int currentSum = array[i] + array[j];
			int difference = targetSum - currentSum;
			if (hashTable.find(difference) != hashTable.end()) {
				for (auto pair : hashTable[difference]) {
					pair.push_back(array[i]);
					pair.push_back(array[j]);
					solution.push_back(pair);
				}
			}
		}
		for (int g = 0; g < i; g++) {
			int currentSum = array[i] + array[g];
			if (hashTable.find(currentSum) == hashTable.end()) {
				hashTable[currentSum] = vector<vector<int>>{ {array[g], array[i]} };
			}
			else {
				hashTable[currentSum].push_back(vector<int>{array[g], array[i]});
			}
		}
	}

	return solution;
}
