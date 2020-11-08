#include <vector>
using namespace std;

bool dimensionsValid(vector<int>, vector<int>);
vector<vector<int>> buildSequence(vector<vector<int>>, vector<int>, int);

vector<vector<int>> diskStacking(vector<vector<int>> disks) {
	sort(disks.begin(), disks.end(),
		[](vector<int>& a, vector<int>& b) { return a[2] < b[2]; });

	vector<int> heights;
	for (auto dimensions : disks) {
		heights.push_back(dimensions[2]);
	}

	vector<int> sequences;
	for (auto _ : disks) {
		sequences.push_back(INT_MIN);
	}
	int maxHeightIdx{ 0 };
	for (int i = 1; i < disks.size(); i++) {
		vector<int> current = disks[i];
		for (int j = 0; j < i; j++) {
			vector<int> other = disks[j];
			if (dimensionsValid(other, current)) {
				if (heights[i] <= current[2] + heights[j]) {
					heights[i] = current[2] + heights[j];
					sequences[i] = j;
				}
			}
		}
		if (heights[i] >= heights[maxHeightIdx]) {
			maxHeightIdx = i;
		}
	}
	return buildSequence(disks, sequences, maxHeightIdx);
}

bool dimensionsValid(vector<int> a, vector<int> b) {
	return a[0] < b[0] && a[1] < b[1] && a[2] < b[2];
}

vector<vector<int>> buildSequence(vector<vector<int>> disks, vector<int> sequences, int currIdx) {
	vector<vector<int>> sequence;
	while (currIdx != INT_MIN) {
		sequence.insert(sequence.begin(), disks[currIdx]);
		currIdx = sequences[currIdx];
	}
	return sequence;
}