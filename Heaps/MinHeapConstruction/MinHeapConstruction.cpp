#include <vector>
class MinHeap {
public:
    vector<int> heap;

    MinHeap(vector<int> vector) { heap = buildHeap(vector); }

    vector<int> buildHeap(vector<int>& vector) {
        int firstParentIdx = (vector.size() - 2) / 2;
        for (int i = firstParentIdx; i >= 0; i--) {
            siftDown(i, vector.size() - 1, vector);
        }
        return vector;
    }

    void siftDown(int currentIdx, int endIdx, vector<int>& heap) {
        int oneChildIdx = (currentIdx * 2) + 1;
        int smallerChild{ 0 };

        while (oneChildIdx <= endIdx) {
            int twoChildIdx = (currentIdx * 2) + 2 <= endIdx ? (currentIdx * 2) + 2 : -1;
            if (twoChildIdx != -1 && heap[twoChildIdx] < heap[oneChildIdx]) {
                smallerChild = twoChildIdx;
            }
            else {
                smallerChild = oneChildIdx;
            }

            if (heap[smallerChild] < heap[currentIdx]) {
                swap(heap[smallerChild], heap[currentIdx]);
                currentIdx = smallerChild;
                oneChildIdx = (currentIdx * 2) + 1;
            }
            else break;
        }
    }

    void siftUp(int currentIdx, vector<int>& heap) {
        int parentIndex = (currentIdx - 1) / 2;
        while (heap[parentIndex] > heap[currentIdx] && currentIdx > 0) {
            swap(heap[parentIndex], heap[currentIdx]);
            currentIdx = parentIndex;
            parentIndex = (currentIdx - 1) / 2;
        }
    }

    int peek() {
        return this->heap[0];
    }

    int remove() {
        swap(heap[0], heap[heap.size() - 1]);
        int valueToRemove = heap.back();
        heap.pop_back();
        siftDown(0, heap.size() - 1, heap);

        return valueToRemove;
    }

    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1, heap);
    }
};