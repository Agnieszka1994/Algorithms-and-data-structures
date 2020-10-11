#include <functional>
using namespace std;

bool MAX_HEAP(int a, int b);
bool MIN_HEAP(int a, int b);

class Heap {
public:
	vector<int> heap;
	function<bool(int, int)> comparaison;
	int length;

	Heap(function<bool(int, int)> func, vector<int> vector) {
		comparaison = func;
		heap = buildHeap(vector);
		length = heap.size();
	}

	vector<int> buildHeap(vector<int>& vector) {
		int firstParentIdx = (vector.size() - 2) / 2;
		for (int i = firstParentIdx; i >= 0; i--) {
			siftDown(i, vector.size() - 1, vector);
		}
		return vector;
	}
	void siftDown(int currentIdx, int endIdx, vector<int>& heap) {
		int oneChildIdx = (currentIdx * 2) + 1;

		while (oneChildIdx <= endIdx) {
			int twoChildIdx = (currentIdx * 2) + 2 <= endIdx ? (currentIdx * 2) + 2 : -1;
			int idxToSwap;
			if (twoChildIdx != -1) {
				if (comparaison(heap[twoChildIdx], heap[oneChildIdx])) {
					idxToSwap = twoChildIdx;
				}
				else {
					idxToSwap = oneChildIdx;
				}
			}
			else {
				idxToSwap = oneChildIdx;
			}
			if (comparaison(heap[idxToSwap], heap[currentIdx])) {
				swap(heap[idxToSwap], heap[currentIdx]);
				currentIdx = idxToSwap;
				oneChildIdx = (currentIdx * 2) + 1;
			}
			else return;
		}
	}

	void siftUp(int currentIdx, vector<int>& heap) {
		int parentIndex = (currentIdx - 1) / 2;
		while (currentIdx > 0) {
			if (comparaison(heap[currentIdx], heap[parentIndex])) {
				swap(heap[parentIndex], heap[currentIdx]);
				currentIdx = parentIndex;
				parentIndex = (currentIdx - 1) / 2;
			}
			else return;
		}
	}

	void insert(int value) {
		heap.push_back(value);
		siftUp(heap.size() - 1, heap);
		length++;
	}
	int remove() {
		swap(heap[0], heap[heap.size() - 1]);
		int valueToRemove = heap.back();
		heap.pop_back();
		length--;
		siftDown(0, heap.size() - 1, heap);
		return valueToRemove;
	}
	int peek() {
		return heap[0];
	}
};

class ContinuousMedianHandler {
public:
	Heap lowers;
	Heap graters;
	double median;

	ContinuousMedianHandler() : lowers(MAX_HEAP, {}), graters(MIN_HEAP, {}) {
		median = 0;
	}

	void insert(int number) {
		if (!lowers.length || number < lowers.peek()) {
			lowers.insert(number);
		}
		else {
			graters.insert(number);
		}
		rebalanceHeaps();
		updateMedian();
	}
	void rebalanceHeaps() {
		if (lowers.length - graters.length == 2) {
			graters.insert(lowers.remove());
		}
		else if (graters.length - lowers.length == 2) {
			lowers.insert(graters.remove());
		}
	}

	void updateMedian() {
		if (lowers.length == graters.length) {
			median = ((double)lowers.peek() + (double)graters.peek()) / 2;
		}
		else if (lowers.length > graters.length) {
			median = lowers.peek();
		}
		else {
			median = graters.peek();
		}

	}

	double getMedian() { return median; }
};

bool MAX_HEAP(int a, int b) {
	return a > b;
}
bool MIN_HEAP(int a, int b) {
	return a < b;
}