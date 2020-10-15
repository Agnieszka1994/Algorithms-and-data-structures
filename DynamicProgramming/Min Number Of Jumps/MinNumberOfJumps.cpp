#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int minNumberOfJumps(vector<int> array) {

	//this array will store the number of jumps needed 
	// to go from 0 to each index of the array
	vector<int> jumps(array.size(), INT_MAX);
	jumps[0] = 0;

	for (int i = 1; i < array.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (array[j] >= i - j) {
				jumps[i] = min(jumps[j] + 1, jumps[i]);
			}
		}
	}
	return jumps[array.size() - 1];
}