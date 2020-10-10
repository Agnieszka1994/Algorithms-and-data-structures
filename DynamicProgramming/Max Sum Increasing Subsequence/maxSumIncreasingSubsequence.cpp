#include <vector>
using namespace std;
vector<vector<int>> buildSequence(vector<int> array, vector<int> sequences, int currentIdx, int sum);

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
	vector<int> maxIncreasingSums = array;
	vector<int> sequences(array.size(), INT_MIN);
	int maxSumIdx{ 0 };
	for (int i = 0; i < array.size(); i++) {
		int currentNum = array[i];
		for (int j = 0; j < i; j++) {
			int otherNum = array[j];
			if (otherNum < currentNum && maxIncreasingSums[j] + currentNum >= maxIncreasingSums[i]) {
				maxIncreasingSums[i] = maxIncreasingSums[j] + currentNum;
				sequences[i] = j;
			}
		}
		if (maxIncreasingSums[i] >= maxIncreasingSums[maxSumIdx]) {
			maxSumIdx = i;
		}
	}
	return buildSequence(array, sequences, maxSumIdx, maxIncreasingSums[maxSumIdx]);
}

vector<vector<int>> buildSequence(vector<int> array, vector<int> sequences, int currentIdx, int sum) {

	vector<vector<int>> sequence = {{},{}};
	sequence[0].push_back(sum);
	while (currentIdx != INT_MIN) {
		sequence[1].insert(sequence[1].begin(), array[currentIdx]);
		currentIdx = sequences[currentIdx];
	}
	return sequence;
}