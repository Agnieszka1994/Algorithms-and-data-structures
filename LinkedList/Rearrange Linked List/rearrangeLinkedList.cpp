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

struct PairOfLists {
	LinkedList* head;
	LinkedList* tail;
};

PairOfLists addToList(LinkedList* head, LinkedList* tail, LinkedList* node);
PairOfLists connectLists(LinkedList* headOne, LinkedList* tailOne, LinkedList* headTwo, LinkedList* tailTwo);

LinkedList* rearrangeLinkedList(LinkedList* head, int k) {
	LinkedList* headOfSmaller = nullptr;
	LinkedList* tailOfSmaller = nullptr;
	LinkedList* headOfGreater = nullptr;
	LinkedList* tailOfGreater = nullptr;
	LinkedList* headOfEqual = nullptr;
	LinkedList* tailOfEqual = nullptr;

	LinkedList* currentNode = head;
	while (currentNode != nullptr) {
		if (currentNode->value < k) {
			PairOfLists smallerList = addToList(headOfSmaller, tailOfSmaller, currentNode);
			headOfSmaller = smallerList.head;
			tailOfSmaller = smallerList.tail;
		}
		else if (currentNode->value > k) {
			PairOfLists greaterList = addToList(headOfGreater, tailOfGreater, currentNode);
			headOfGreater = greaterList.head;
			tailOfGreater = greaterList.tail;
		}
		else {
			PairOfLists equalList = addToList(headOfEqual, tailOfEqual, currentNode);
			headOfEqual = equalList.head;
			tailOfEqual = equalList.tail;
		}
		LinkedList* prevNode = currentNode;
		currentNode = currentNode->next;
		prevNode->next = nullptr;
	}
	PairOfLists first = connectLists(headOfSmaller, tailOfSmaller, headOfEqual, tailOfEqual);
	PairOfLists solution = connectLists(first.head, first.tail, headOfGreater, tailOfGreater);
	return solution.head;
}

PairOfLists addToList(LinkedList* head, LinkedList* tail, LinkedList* node) {
	LinkedList* newHead = head;
	LinkedList* newTail = node;

	if (newHead == nullptr)
		newHead = node;
	if (tail != nullptr)
		tail->next = node;
	return PairOfLists{ newHead, newTail };
}

PairOfLists connectLists(LinkedList* headOne, LinkedList* tailOne, LinkedList* headTwo, LinkedList* tailTwo) {
	LinkedList* newHead = headOne == nullptr ? headTwo : headOne;
	LinkedList* newTail = tailTwo == nullptr ? tailOne : tailTwo;

	if (tailOne != nullptr)
		tailOne->next = headTwo;
	return PairOfLists{ newHead, newTail };
}