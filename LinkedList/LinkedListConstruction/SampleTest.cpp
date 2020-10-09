#include "pch.h"
#include "LinkedListConstruction.cpp"
#include <vector>

Node::Node(int value) {
    this->value = value;
    prev = NULL;
    next = NULL;
};

vector<int> getNodeValuesHeadToTail(DoublyLinkedList linkedList) {
    vector<int> values = {};
    Node* node = linkedList.head;
    while (node != NULL) {
        values.push_back(node->value);
        node = node->next;
    }
    return values;
}

vector<int> getNodeValuesTailToHead(DoublyLinkedList linkedList) {
    vector<int> values = {};
    Node* node = linkedList.tail;
    while (node != NULL) {
        values.push_back(node->value);
        node = node->prev;
    }
    return values;
}

void bindNodes(Node* nodeOne, Node* nodeTwo) {
    nodeOne->next = nodeTwo;
    nodeTwo->prev = nodeOne;
}


TEST(SampleTest, Test) {
    DoublyLinkedList linkedList;
    Node one(1);
    Node two(2);
    Node three(3);
    Node three2(3);
    Node three3(3);
    Node four(4);
    Node five(5);
    Node six(6);
    bindNodes(&one, &two);
    bindNodes(&two, &three);
    bindNodes(&three, &four);
    bindNodes(&four, &five);
    linkedList.head = &one;
    linkedList.tail = &five;

    linkedList.setHead(&four);
    assert(getNodeValuesHeadToTail(linkedList) ==
        (vector<int>{4, 1, 2, 3, 5}));
    assert(getNodeValuesTailToHead(linkedList) ==
        (vector<int>{5, 3, 2, 1, 4}));

    linkedList.setTail(&six);
    assert(getNodeValuesHeadToTail(linkedList) ==
        (vector<int>{4, 1, 2, 3, 5, 6}));
    assert(getNodeValuesTailToHead(linkedList) ==
        (vector<int>{6, 5, 3, 2, 1, 4}));

    linkedList.insertBefore(&six, &three);
    assert(getNodeValuesHeadToTail(linkedList) ==
        (vector<int>{4, 1, 2, 5, 3, 6}));
    assert(getNodeValuesTailToHead(linkedList) ==
        (vector<int>{6, 3, 5, 2, 1, 4}));

    linkedList.insertAfter(&six, &three2);
    assert(getNodeValuesHeadToTail(linkedList) ==
        (vector<int>{4, 1, 2, 5, 3, 6, 3}));
    assert(getNodeValuesTailToHead(linkedList) ==
        (vector<int>{3, 6, 3, 5, 2, 1, 4}));

    linkedList.insertAtPosition(1, &three3);
    assert(getNodeValuesHeadToTail(linkedList) ==
        (vector<int>{3, 4, 1, 2, 5, 3, 6, 3}));
    assert(getNodeValuesTailToHead(linkedList) ==
        (vector<int>{3, 6, 3, 5, 2, 1, 4, 3}));

    linkedList.removeNodesWithValue(3);
    assert(getNodeValuesHeadToTail(linkedList) ==
        (vector<int>{4, 1, 2, 5, 6}));
    assert(getNodeValuesTailToHead(linkedList) ==
        (vector<int>{6, 5, 2, 1, 4}));

    linkedList.remove(&two);
    assert(getNodeValuesHeadToTail(linkedList) == (vector<int>{4, 1, 5, 6}));
    assert(getNodeValuesTailToHead(linkedList) == (vector<int>{6, 5, 1, 4}));

    assert(linkedList.containsNodeWithValue(5) == true);
}
