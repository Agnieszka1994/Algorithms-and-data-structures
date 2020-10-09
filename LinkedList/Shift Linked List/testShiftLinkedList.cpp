#include "pch.h"
#include "ShiftLinkedList.cpp"

vector<int> linkedListToArray(LinkedList* head) {
    vector<int> array{};
    auto current = head;
    while (current != NULL) {
        array.push_back(current->value);
        current = current->next;
    }
    return array;
}

TEST(SampleTestCase_1, SampleTest) {
    auto head = new LinkedList(0);
    head->next = new LinkedList(1);
    head->next->next = new LinkedList(2);
    head->next->next->next = new LinkedList(3);
    head->next->next->next->next = new LinkedList(4);
    head->next->next->next->next->next = new LinkedList(5);
    auto result = shiftLinkedList(head, 2);
    auto array = linkedListToArray(result);

    vector<int> expected{ 4, 5, 0, 1, 2, 3 };
    assert(expected == array);
};
