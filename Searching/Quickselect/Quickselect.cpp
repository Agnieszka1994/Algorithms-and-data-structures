#include <vector>
using namespace std;

int quickselectHelper(vector<int> array, int startIdx, int endIdx, int position);

int quickselect(vector<int> array, int k) {
	int position = k - 1;
	return quickselectHelper(array, 0, array.size() - 1, position);
}

int quickselectHelper(vector<int> array, int startIdx, int endIdx, int position) {

	while (true) {
		if (startIdx > endIdx) {
			return 0;
		}
		int pivot = startIdx;
		int leftIdx = startIdx + 1;
		int rightIdx = endIdx;
		while (leftIdx <= rightIdx) {
			if (array[leftIdx] > array[pivot] && array[rightIdx] < array[pivot]) {
				swap(array[leftIdx], array[rightIdx]);
			}
			if (array[leftIdx] <= array[pivot]) {
				leftIdx++;
			}
			if (array[rightIdx] >= array[pivot]) {
				rightIdx--;
			}
		}
		swap(array[pivot], array[rightIdx]);
		if (rightIdx == position) {
			return array[rightIdx];
		}
		else if (rightIdx < position) {
			startIdx = rightIdx + 1;
		}
		else {
			endIdx = rightIdx - 1;
		}
	}
}
