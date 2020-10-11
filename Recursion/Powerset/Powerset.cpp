#include <vector>
using namespace std;

vector<vector<int>> powerset(vector<int> array) {
	vector<vector<int>> subsets{ {} };

	for (auto el : array) {
		int len = subsets.size();
		for (int i = 0; i < len; i++) {
			vector<int> currentSubset = subsets[i];
			currentSubset.push_back(el);
			subsets.push_back(currentSubset);
		}
	}
	return subsets;
}