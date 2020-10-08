#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;
int distanceBetween(int i, int j);
int getIndexAtMinValue(vector<int>);
int apartmentHunting(vector<unordered_map<string, bool>> blocks,
	vector<string> reqs) {

	vector<int> maxDistanceAtBlock(blocks.size(), INT_MIN);

	for (int i = 0; i < blocks.size(); i++) {
		for (auto req : reqs) {
			int closestReqDistance = INT_MAX;
			for (int j = 0; j < blocks.size(); j++) {
				if (blocks[j].at(req)) {
					closestReqDistance = min(closestReqDistance, distanceBetween(i, j));
				}
			}
			maxDistanceAtBlock[i] = max(closestReqDistance, maxDistanceAtBlock[i]);
		}
	}


	return getIndexAtMinValue(maxDistanceAtBlock);
}
int distanceBetween(int i, int j) {
	return abs(i-j);
}
int getIndexAtMinValue(vector<int> array) {
	int indexAtMinValue = 0;
	int minValue = INT_MAX;
	for (int i = 0; i < array.size(); i++) {
		if (array[i] < minValue) {
			minValue = array[i];
			indexAtMinValue = i;
		}
	}
	return indexAtMinValue;
}