#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
	vector<vector<int>> triplets;
	sort(array.begin(), array.end());

	for (int current = 0; current < array.size(); current++) {
		int left = current + 1;
		int right = array.size() - 1;
		while (left < right) {
			if ((array[current] + array[left] + array[right]) < targetSum) {
				left++;
			}
			else if ((array[current] + array[left] + array[right]) > targetSum) {
				right--;
			}
			else {
				triplets.push_back(vector<int>{ array[current], array[left], array[right] });
				left++;
				right--;
			}
		}

}

	return triplets;
}