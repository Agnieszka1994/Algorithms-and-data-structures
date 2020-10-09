#include <vector>

using namespace std;

class LinkedList {
public:
	int value;
	LinkedList *next;

	LinkedList(int value) {
    this->value = value;
    next = NULL;
  }
};

LinkedList* mergeLinkedLists(LinkedList* headOne, LinkedList* headTwo) {

	LinkedList* currentOne = headOne;
	LinkedList* prevOne = NULL;
	LinkedList* currentTwo = headTwo;
	while (currentOne != NULL && currentTwo != NULL) {
		if (currentOne->value < currentTwo->value) {
			prevOne = currentOne;
			currentOne = currentOne->next;
		}
		else {
			if (prevOne != NULL)//insert before
				prevOne->next = currentTwo; 
			//if prev is NULL - set node from 2nd list as head 
			prevOne = currentTwo;
			currentTwo = currentTwo->next;
			prevOne->next = currentOne;
		}
	}
	if (currentOne == NULL) {
		prevOne->next = currentTwo;
	}
	return headOne->value < headTwo->value ? headOne : headTwo;

}