#include <vector>
using namespace std;

void constructPermutations(vector<int>, vector<int>, vector<vector<int>>*);

vector<vector<int>> getPermutations(vector<int> array) {
	vector<vector<int>> solution;
	constructPermutations(array, {}, &solution);
	return solution;
}

void constructPermutations(vector<int> array, vector<int> currentPerm, vector<vector<int>>* solution) {
	if ((!array.size()) && currentPerm.size()) {
		solution->push_back(currentPerm);
	}
	else {
		for (int i = 0; i < array.size(); i++) {
			vector<int> newArray;
			newArray.insert(newArray.end(), array.begin(), array.begin() + i);
			newArray.insert(newArray.end(), array.begin() + i + 1, array.end());
			vector<int> newPerm = currentPerm;
			newPerm.push_back(array[i]);
			constructPermutations(newArray, newPerm, solution);
		}
	}
}