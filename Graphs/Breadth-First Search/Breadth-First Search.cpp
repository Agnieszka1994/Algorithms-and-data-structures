#include <vector>
using namespace std;

class Node {
public:
    string name;
    vector<Node*> children;

    Node(string str) { name = str; }

    vector<string> breadthFirstSearch(vector<string>* array) {
        queue<Node*> toBeAdded;
        Node* current;
        toBeAdded.push(this);
        while (!toBeAdded.empty()) {
					
            current = toBeAdded.front();
            toBeAdded.pop();
            array->push_back(current->name);
					
            for (auto children : current->children) {
                toBeAdded.push(children);
            }

        }
        return *array;
    }

    Node* addChild(string name) {
        Node* child = new Node(name);
        children.push_back(child);
        return this;
    }
};
