#include "pch.h"
#include "RemoveKthNodeFromEnd.cpp"
#include <vector>

class TestLinkedList : public LinkedList {
public:
    TestLinkedList(int value);
    void addMany(vector<int> values);
    vector<int> getNodesInArray();
};

LinkedList::LinkedList(int value) {
    this->value = value;
    this->next = NULL;
}

TestLinkedList::TestLinkedList(int value) : LinkedList(value) {
    this->value = value;
    this->next = NULL;
}

void TestLinkedList::addMany(vector<int> values) {
    LinkedList* current = this;
    while (current->next != NULL) {
        current = current->next;
    }
    for (int value : values) {
        current->next = new LinkedList(value);
        current = current->next;
    }
}

vector<int> TestLinkedList::getNodesInArray() {
    vector<int> nodes{};
    LinkedList* current = this;
    while (current != NULL) {
        nodes.push_back(current->value);
        current = current->next;
    }
    return nodes;
}

TEST(SampleTestCase_1, SampleTest) {
    TestLinkedList test(0);
    test.addMany({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    TestLinkedList expected(0);
    expected.addMany({ 1, 2, 3, 4, 5, 7, 8, 9 });
    removeKthNodeFromEnd(&test, 4);
    assert(test.getNodesInArray() == expected.getNodesInArray());
};
