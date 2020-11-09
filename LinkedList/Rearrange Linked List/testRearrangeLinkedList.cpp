#include "pch.h"
#include "rearrangeLinkedList.cpp"

vector<int> linkedListToArray(LinkedList* head) {
    vector<int> array{};
    auto current = head;
    while (current != NULL) {
        array.push_back(current->value);
        current = current->next;
    }
    return array;
}
TEST(SampleTestCase1, SampleTest) {
    auto head = new LinkedList(3);
    head->next = new LinkedList(0);
    head->next->next = new LinkedList(5);
    head->next->next->next = new LinkedList(2);
    head->next->next->next->next = new LinkedList(1);
    head->next->next->next->next->next = new LinkedList(4);
    auto result = rearrangeLinkedList(head, 3);
    auto array = linkedListToArray(result);

    vector<int> expected{ 0, 2, 1, 3, 5, 4 };
    assert(expected == array);
};