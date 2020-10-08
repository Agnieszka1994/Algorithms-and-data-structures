using namespace std;

bool isOutOfOrder(int i, int number, vector<int> array);

vector<int> subarraySort(vector<int> array) {

	int minOutOfOrder = INT_MAX;
	int maxOutOfOrder = INT_MIN;

	for (int i = 0; i < array.size(); i++) {
		int num = array[i];
		if (isOutOfOrder(i, num, array)) {
			minOutOfOrder = min(minOutOfOrder, num);
			maxOutOfOrder = max(maxOutOfOrder, num);
		}
	}
		if (minOutOfOrder == INT_MAX) {
			return vector<int>{-1, -1};
		}

		int leftIdx = 0;
		while (minOutOfOrder >= array[leftIdx]) {
			leftIdx++;
		}

		int rightIdx = array.size() -1;
		while (maxOutOfOrder <= array[rightIdx]) {
			rightIdx--;
		}
	
	return vector<int>{leftIdx, rightIdx};
}

bool isOutOfOrder(int i, int number, vector<int> array) {
	if (i == 0) {
		return number > array[i + 1];
	}
	if (i == array.size() - 1) {
		return number < array[i - 1];
	}
	return number < array[i - 1] || number > array[i + 1];
}