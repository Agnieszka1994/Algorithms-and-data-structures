#include <vector>
using namespace std;

int waterArea(vector<int> heights) {
	int leftPillar = 0;
	int rightPillar = 0;
	vector<int> maxLeftHeights(heights.size() );
	vector<int> maxRightHeights(heights.size());
	int sumOfWater = 0;

	for (int i = 0; i < heights.size(); i++) {
		maxLeftHeights[i] = leftPillar;
		if (leftPillar < heights[i])
			leftPillar = heights[i];
	}
	for (int i = heights.size() - 1; i >= 0; i--) {
		maxRightHeights[i] = rightPillar;
		if (rightPillar < heights[i])
			rightPillar = heights[i];
	}
	for (int i = 0; i < heights.size(); i++) {
		int currentSumOfWater = min(maxLeftHeights[i], maxRightHeights[i]) - heights[i];
		if (currentSumOfWater > 0)
			sumOfWater += currentSumOfWater;
	}
	return sumOfWater;
}