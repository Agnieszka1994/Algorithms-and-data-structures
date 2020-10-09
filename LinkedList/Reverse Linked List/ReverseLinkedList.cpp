using namespace std;

class LinkedList {
public:
	int value;
	LinkedList *next;

	LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};

LinkedList *reverseLinkedList(LinkedList *head) {
	LinkedList * currentNode = head;
	LinkedList* nextNode = head->next;
	LinkedList * previousNode = NULL;
	
	while(currentNode!=NULL){
		
		nextNode = currentNode->next;	
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
			
	}
	return previousNode;
}
