#include <vector>
using namespace std;

using namespace std;
void quickSortHelper(vector<int>& array, int startPtr, int endPtr);
vector<int> quickSort(vector<int> array) {
	quickSortHelper(array, 0, array.size() - 1);
	return array;
}


void quickSortHelper(vector<int>& array, int startPtr, int endPtr) {
	if (startPtr >= endPtr) {
		return;
	}

	int pivot = startPtr;
	int leftPtr = startPtr + 1;
	int rightPtr = endPtr;
	while (rightPtr >= leftPtr) {
		if (array.at(leftPtr) > array.at(pivot) && array.at(rightPtr) < array.at(pivot)) {
			swap(array[leftPtr], array[rightPtr]);
		}
		if (array.at(leftPtr) <= array.at(pivot)) {
			leftPtr++;
		}
		if (array.at(rightPtr) >= array.at(pivot)) {
			rightPtr--;
		}
	}

	swap(array[pivot], array[rightPtr]);
	bool leftIsSmaller = rightPtr - 1 - startPtr < endPtr - (rightPtr + 1);
	if (leftIsSmaller) {
		quickSortHelper(array, startPtr, rightPtr - 1);
		quickSortHelper(array, rightPtr + 1, endPtr);
	}
	else {
		quickSortHelper(array, rightPtr + 1, endPtr);
		quickSortHelper(array, startPtr, rightPtr - 1);
	}

}