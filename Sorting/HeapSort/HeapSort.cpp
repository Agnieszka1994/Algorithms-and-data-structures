#include <vector>
using namespace std;

void buildMaxHeap(vector<int>&);
void siftDown(int, int, vector<int>&);


vector<int> heapSort(vector<int> array) {
	buildMaxHeap(array);
	for (int i = array.size() - 1; i > 0; i--) {
		swap(array[0], array[i]);
		siftDown(0, i-1, array);
	}
		return array;
}

void buildMaxHeap(vector<int>&array) {

	int firstParentIdx = (array.size() - 1) / 2;
	for (int i = firstParentIdx; i >= 0; i--) {
		siftDown(i, array.size() - 1, array);
	}

}

void siftDown(int toBeSifted, int endIdx, vector<int>&array) {
    int oneChildIdx = (toBeSifted * 2) + 1;
    int graterChild{ 0 };

    while (oneChildIdx <= endIdx) {
        int twoChildIdx = (toBeSifted * 2) + 2 <= endIdx ? (toBeSifted * 2) + 2 : -1;
        if (twoChildIdx != -1 && array[twoChildIdx] > array[oneChildIdx]) {
            graterChild = twoChildIdx;
        }
        else {
            graterChild = oneChildIdx;
        }

        if (array[graterChild] > array[toBeSifted]) {
            swap(array[graterChild], array[toBeSifted]);
            toBeSifted = graterChild;
            oneChildIdx = (toBeSifted * 2) + 1;
        }
        else break;
    }

}