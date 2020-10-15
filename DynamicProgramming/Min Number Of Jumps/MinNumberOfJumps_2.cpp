#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int minNumberOfJumps(vector<int> array) {
	if (array.size() == 1) {
		return 0;
	}
	int numOfJumps = 0;
	int maxReach = array[0];
	int steps = array[0];
	for (int i = 1; i < array.size() - 1; i++) {
		maxReach = max(maxReach, array[i] + i);
		steps--;
		if (steps == 0) {
			numOfJumps++;
			steps = maxReach - i;
		}
	}
	return numOfJumps + 1;
}