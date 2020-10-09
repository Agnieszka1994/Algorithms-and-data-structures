#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;
	bool visited = false; 
  LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head) {
  
	while(!head->visited){
		head->visited = true;
		head = head->next;
	}
	
  return head;
}
