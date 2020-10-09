#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left = NULL;
  BinaryTree *right = NULL;

  BinaryTree(int value);
};

void mutate(BinaryTree* node, BinaryTree* parent, bool isLeftChild);
BinaryTree* rightSiblingTree(BinaryTree* root) {
	mutate(root, nullptr, false);
	return root;
}

void mutate(BinaryTree* node, BinaryTree* parent, bool isLeftChild) {
	if (node == nullptr)
		return;

	BinaryTree* left = node->left;
	BinaryTree* right = node->right;
	
	mutate(left, node, true);
	
	if (parent == nullptr) {
		node->right = nullptr;
	}
	else if(isLeftChild)
	{
		node->right = parent->right;
	}
	else {
		if (parent->right == nullptr) {
			node->right = nullptr; 
		}
		else {
			node->right = parent->right->left;
		}
	}
		 
	mutate(right, node, false);
}