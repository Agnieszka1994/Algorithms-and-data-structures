#include "pch.h"
#include "ReverseLinkedList.cpp"
#include <vector>

LinkedList* newLinkedList(vector<int> values);
vector<int> toArray(LinkedList* ll);
bool arraysEqual(vector<int> arr1, vector<int> arr2);

TEST(SampleTestCase_1, SampleTest) {
    LinkedList* test = newLinkedList({ 0, 1, 2, 3, 4, 5 });
    vector<int> result = toArray(reverseLinkedList(test));
    vector<int> expected = { 5, 4, 3, 2, 1, 0 };
    assert(arraysEqual(result, expected));
};

LinkedList* newLinkedList(vector<int> values) {
    LinkedList* ll = new LinkedList(values[0]);
    LinkedList* current = ll;
    for (int i = 1; i < values.size(); i++) {
        current->next = new LinkedList(values[i]);
        current = current->next;
    }
    return ll;
}

vector<int> toArray(LinkedList* ll) {
    vector<int> arr = {};
    LinkedList* current = ll;
    while (current != NULL) {
        arr.push_back(current->value);
        current = current->next;
    }
    return arr;
}

bool arraysEqual(vector<int> arr1, vector<int> arr2) {
    if (arr1.size() != arr2.size())
        return false;
    for (int i = 0; i < arr1.size(); i++) {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}


