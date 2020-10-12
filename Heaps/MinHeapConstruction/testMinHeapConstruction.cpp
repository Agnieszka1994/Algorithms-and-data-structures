#include "pch.h"
#include "MinHeapConstruction.cpp"
#include <vector>
#include <algorithm>

bool heapPropertySatisfied(vector<int> array) {
    for (int currentIdx = 1; currentIdx < array.size(); currentIdx++) {
        int parentIdx = (currentIdx - 1) / 2;
        if (parentIdx < 0) {
            return true;
        }
        if (array[parentIdx] > array[currentIdx]) {
            return false;
        }
    }
    return true;
}

TEST(SampleTestCase1, SampleTest) {
    MinHeap minHeap({ 48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41 });
    minHeap.insert(76);
    assert(heapPropertySatisfied(minHeap.heap));
    assert(minHeap.peek() == -5);
    assert(minHeap.remove() == -5);
    assert(heapPropertySatisfied(minHeap.heap));
    assert(minHeap.peek() == 2);
    assert(minHeap.remove() == 2);
    assert(heapPropertySatisfied(minHeap.heap));
    assert(minHeap.peek() == 6);
    minHeap.insert(87);
    assert(heapPropertySatisfied(minHeap.heap));
};