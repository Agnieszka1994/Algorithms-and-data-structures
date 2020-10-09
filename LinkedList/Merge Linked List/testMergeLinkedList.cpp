#include "pch.h"
#include "MergeLinkedList.cpp"
#include <vector>

LinkedList* addMany(LinkedList* ll, vector<int> values) {
    LinkedList* current = ll;
    while (current->next != NULL) {
        current = current->next;
    }
    for (auto value : values) {
        current->next = new LinkedList(value);
        current = current->next;
    }
    return ll;
}

vector<int> getNodesInArray(LinkedList* ll) {
    vector<int> nodes;
    LinkedList* current = ll;
    while (current != NULL) {
        nodes.push_back(current->value);
        current = current->next;
    }
    return nodes;
}

TEST(SampleTestCase_1, SampleTest) {
    LinkedList* list1 = new LinkedList(2);
    addMany(list1, { 6, 7, 8 });
    LinkedList* list2 = new LinkedList(1);
    addMany(list2, { 3, 4, 5, 9, 10 });
    LinkedList* output = mergeLinkedLists(list1, list2);
    vector<int> expectedNodes = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    assert(getNodesInArray(output) == expectedNodes);
};
