#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree *parent;

  BinaryTree(int value, BinaryTree *parent = NULL);
  void insert(vector<int> values, int i = 0);
};

void iterativeInOrderTraversal(BinaryTree* tree,
	void (*callback)(BinaryTree* tree)) {
	BinaryTree* currentNode = tree;
	BinaryTree* previous = NULL;

	while (currentNode != NULL){
		BinaryTree* nextNode;
		if (previous == nullptr || previous == currentNode->parent) {
			if (currentNode->left != NULL)
				nextNode = currentNode->left;
			else {
				(*callback)(currentNode);
				nextNode = currentNode->right != NULL ? currentNode->right : currentNode->parent;
			}
		}
		else if (previous == currentNode->left) {
			(*callback)(currentNode);
			nextNode = currentNode->right != NULL ? currentNode->right : currentNode->parent;
		}
		else {
			nextNode = currentNode->parent;
		}
		previous = currentNode;
		currentNode = nextNode;
	}
}
