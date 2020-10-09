using namespace std;

class LinkedList {
public:
	int value;
	LinkedList* next;

	LinkedList(int value) {
		this->value = value;
		next = NULL;
	}
};

LinkedList* shiftLinkedList(LinkedList* head, int k) {

	int listLen = 1;
	LinkedList* currentTail = head;
	while (currentTail->next != NULL) {
		currentTail = currentTail->next;
		listLen++;
	}
	k = k % listLen;

	if (k > 0) {
		LinkedList* firstPtr = head;
		LinkedList* secondPtr = head;
		int count = 1;
		while (count <= k) {
			secondPtr = secondPtr->next;
			count++;
		}
		while (secondPtr->next != NULL) {
			secondPtr = secondPtr->next;
			firstPtr = firstPtr->next;
		}
		LinkedList* newHead = firstPtr->next;
		firstPtr->next = NULL;
		secondPtr->next = head;
		return newHead;
	}
	else if (k < 0) {
		LinkedList* newHead = head;
		LinkedList* newTail = NULL;
		int counter = k;
		while (counter < 0) {
			newTail = newHead;
			newHead = newHead->next;
			counter++;
		}
		currentTail->next = head;
		newTail->next = NULL;
		return newHead;
	}
	else return head;
}