#include <vector>
using namespace std;
int shiftedBinarySearchHelper(vector<int> array, int target, int leftPtr, int rightPtr);

int shiftedBinarySearch(vector<int> array, int target) {
	return shiftedBinarySearchHelper(array, target, 0, array.size() - 1);
}

int shiftedBinarySearchHelper(vector<int> array, int target, int leftPtr, int rightPtr) {
	if (leftPtr > rightPtr)
		return -1;
	int middlePtr = (leftPtr + rightPtr) / 2;
	int potentialMatch = array[middlePtr];
	int leftNumber = array[leftPtr];
	int rightNumber = array[rightPtr];

	if (target == potentialMatch)
		return middlePtr;
	else if (leftNumber <= potentialMatch) {
		if (target < potentialMatch && target >= leftNumber) {
			return shiftedBinarySearchHelper(array, target, leftPtr, middlePtr - 1);
		}
		else
		{
			return shiftedBinarySearchHelper(array, target, middlePtr + 1, rightPtr);
		}	
	}
	else {
		if (target > potentialMatch && target <= rightNumber) {
			return shiftedBinarySearchHelper(array, target, middlePtr + 1, rightPtr);
		}
		else
		{
			return shiftedBinarySearchHelper(array, target, leftPtr, middlePtr - 1);
		}
	}
}