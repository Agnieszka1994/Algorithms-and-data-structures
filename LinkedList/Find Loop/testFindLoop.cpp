#include "pch.h"
#include "FindLoop_2.cpp"

LinkedList::LinkedList(int value) {
    this->value = value;
    this->next = NULL;
}

void addMany(LinkedList* ll, vector<int> values) {
    LinkedList* current = ll;
    while (current->next != NULL) {
        current = current->next;
    }
    for (int value : values) {
        current->next = new LinkedList(value);
        current = current->next;
    }
}

LinkedList* getNthNode(LinkedList* ll, int n) {
    int counter = 1;
    LinkedList* current = ll;
    while (counter < n) {
        current = current->next;
        counter++;
    }
    return current;
}

TEST(SampleTestCase_1, SampleTest) {
    LinkedList test(0);
    addMany(&test, { 1, 2, 3, 4, 5, 6, 7, 8, 9 });
    getNthNode(&test, 10)->next = getNthNode(&test, 5);
    assert(findLoop(&test) == getNthNode(&test, 5));
};
