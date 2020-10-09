#include <unordered_map>

using namespace std;

class DLLNode {
public:
	string key;
	int value;
	DLLNode* next;
	DLLNode* prev;
	DLLNode(string key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {};

	void removeBindings() {
		if (this->prev != nullptr) {
			this->prev->next = this->next;
		}
		if (this->next != nullptr) {
			this->next->prev = this->prev;
		}
		this->prev = nullptr;
		this->next = nullptr;
	}
};

class DoublyLinkedList {
public:
	DLLNode* head;
	DLLNode* tail;
	DoublyLinkedList() :head(nullptr), tail(nullptr) {};

	void setHeadTo(DLLNode* node) {
		if (this->head == node) {
			return;
		}
		else if (this->head == nullptr) {
			this->head = node;
			this->tail = node;
		}
		else if (this->head == this->tail) {
			this->tail->prev = node;
			this->head = node;
			this->head->next = this->tail;
		}
		else {
			if (this->tail == node) {
				this->removeTail();
			}
			node->removeBindings();
			this->head->prev = node;
			node->next = this->head;
			this->head = node;
		}
	}
	void removeTail() {
		if (this->tail == nullptr) {
			return;
		}
		if (this->tail == this->head) {
			this->tail = nullptr;
			this->head = nullptr;
			return;
		}
		this->tail = this->tail->prev;
		this->tail->next = nullptr;
	}
};

class LRUCache {
public:
	unordered_map<string, DLLNode*> cache;
	int maxSize;
	int currentSize;
	DoublyLinkedList listOfRecent;

	LRUCache(int maxSize) {
		this->maxSize = maxSize > 1 ? maxSize : 1;
		this->listOfRecent = DoublyLinkedList();
		this->currentSize = 0;
	}

	void insertKeyValuePair(string key, int value) {
		if (this->cache.find(key) == this->cache.end()) {
			if (this->currentSize == this->maxSize) {
				this->evictLastRecent();
			}
			else {
				this->currentSize++;
			}
			this->cache[key] = new DLLNode(key, value);
		}
		else {
			this->replaceKey(key, value);
		}
		this->updateMostRecent(this->cache[key]);
	}

	int* getValueFromKey(string key) {
		if (this->cache.find(key) == this->cache.end()) {
			return nullptr;
		}
		this->updateMostRecent(this->cache[key]);
		return &this->cache[key]->value;
	}

	string getMostRecentKey() {
		if (this->listOfRecent.head == nullptr) {
			return "";
		}
		else {
			return this->listOfRecent.head->key;
		}
	}

	void evictLastRecent() {
		string keyToRemove = this->listOfRecent.tail->key;
		this->listOfRecent.removeTail();
		this->cache.erase(keyToRemove);
	}

	void updateMostRecent(DLLNode* node) {
		this->listOfRecent.setHeadTo(node);
	}

	void replaceKey(string key, int value) {
		if (this->cache.find(key) == this->cache.end()) {
			return;
		}
		this->cache[key]->value = value;
	}
};
