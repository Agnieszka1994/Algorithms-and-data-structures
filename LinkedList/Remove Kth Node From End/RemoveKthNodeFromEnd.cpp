#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList* head, int k) {
	int count = 1;
	LinkedList* firstPtr = head;
	LinkedList* secondPtr = head;
	
	while (count <= k) {
		secondPtr = secondPtr->next;
		count++;
	}
	if (secondPtr == nullptr) {
		head->value = head->next->value;
		head->next = head->next->next;
		return;
	}
	while (secondPtr->next != nullptr) {
		secondPtr = secondPtr->next;
		firstPtr = firstPtr->next;
	}
	firstPtr->next = firstPtr->next->next;
}
