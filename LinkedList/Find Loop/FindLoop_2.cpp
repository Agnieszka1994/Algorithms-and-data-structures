#include <unordered_map>

using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;
  LinkedList(int value);
};

LinkedList* findLoop(LinkedList* head) {

	unordered_map<LinkedList*, bool> visited;

	while (true) {
		if (visited.find(head) == visited.end()) {
			visited.insert(pair<LinkedList*, bool>(head, true));
		}
		else return head;
		
		head = head->next;
	}

	return head;
}