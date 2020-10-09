using namespace std;

class Node {
public:
  int value;
  Node *prev;
  Node *next;

  Node(int value);
};


class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void setHead(Node* node) {
        if (head == NULL) {
            head = node;
            tail = node;
            return;
        }
        insertBefore(head, node);
    }

    void setTail(Node* node) {
        if (tail == NULL) {
            setHead(node);
            return;
        }
        insertAfter(tail, node);
    }

    void insertBefore(Node* node, Node* nodeToInsert) {
        if (nodeToInsert == head && nodeToInsert == tail)
            return;
			
        remove(nodeToInsert);
        nodeToInsert->prev = node->prev;
        nodeToInsert->next = node;

        if (node->prev == NULL) {
            head = nodeToInsert;
        } else {
            node->prev->next = nodeToInsert;
        }
        node->prev = nodeToInsert;

    }

    void insertAfter(Node* node, Node* nodeToInsert) {
        if (nodeToInsert == head && nodeToInsert == tail) 
					return;

        remove(nodeToInsert);
        nodeToInsert->prev = node;
        nodeToInsert->next = node->next;
        if (node->next == NULL) {
            tail = nodeToInsert;
        }
        else {
            node->next->prev = nodeToInsert;
        }
        node->next = nodeToInsert;
    }

    void insertAtPosition(int position, Node* nodeToInsert) {
        if (position == 1) {
            setHead(nodeToInsert);
            return;
        }
        Node* currentNode = head;
        int posIdx = 1;
        while (currentNode != NULL && posIdx++ != position)
            currentNode = currentNode->next;
        if (currentNode != NULL) {
            insertBefore(currentNode, nodeToInsert);
        }
        else {
            setTail(nodeToInsert);
        }
    }

    void removeNodesWithValue(int value) {
        Node* currentNode = head;

        while (currentNode != NULL) {
            Node* nodeToRemove = currentNode;
            currentNode = currentNode->next;
            if (nodeToRemove->value == value)
                remove(nodeToRemove);
        }
    }

    void remove(Node* node) {
        if (node == head) {
            head = head->next;
        }
        if (node == tail) {
            tail = tail->prev;
           
        }
			 removeNodeBindings(node);

    }

    bool containsNodeWithValue(int value) {
        Node* currentNode = head;

        while (currentNode != NULL && currentNode->value != value)
            currentNode = currentNode->next;

        return currentNode != NULL;
    }

    void removeNodeBindings(Node* node) {
        if (node->prev != NULL)
            node->prev->next = node->next;
        if (node->next != NULL)
            node->next->prev = node->prev;

        node->next = NULL;
        node->prev = NULL;
    }
};