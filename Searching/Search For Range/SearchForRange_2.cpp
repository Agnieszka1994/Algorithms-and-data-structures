#include <vector>
using namespace std;
int findLeftIndex(vector<int> array, int target, int left, int right);
int findRightIndex(vector<int> array, int target, int left, int right);


vector<int> searchForRange(vector<int> array, int target) {
	int leftIdx = findLeftIndex(array, target, 0, array.size() - 1);
	int rightIdx = findRightIndex(array, target, 0, array.size() - 1);
	return { leftIdx, rightIdx };
}

int findLeftIndex(vector<int> array, int target, int left, int right) {
	if (left > right) {
		return -1;
	}
	int middle = (left + right) / 2;
	if (array[middle] == target) {
		if (array[middle - 1] != target || middle == 0)
			return middle;
		else {
			return findLeftIndex(array, target, left, middle - 1);
		}
	}
	else if (array[middle] > target) {
		return findLeftIndex(array, target, left, middle - 1);
	}
	else {
		return findLeftIndex(array, target, middle + 1, right);
	}
}
int findRightIndex(vector<int> array, int target, int left, int right) {
	if (left > right) {
		return -1;
	}
	int middle = (left + right) / 2;
	if (array[middle] == target) {
		if (array[middle + 1] != target || middle == array.size() - 1)
			return middle;
		else {
			return findRightIndex(array, target, middle + 1, right);
		}
	}
	else if (array[middle] > target) {
		return findRightIndex(array, target, left, middle - 1);
	}
	else {
		return findRightIndex(array, target, middle + 1, right);
	}
}
