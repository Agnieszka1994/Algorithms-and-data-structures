#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
	int currentMax{ array[0] };
	int maxSoFar{ array[0] };

	for (int i = 1; i < array.size(); i++) {

		currentMax = max(array[i], currentMax + array[i]);
		maxSoFar = max(maxSoFar, currentMax);
	}
	return maxSoFar;
}