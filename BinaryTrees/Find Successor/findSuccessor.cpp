#include <vector> 

using namespace std;


// This is an input class. Do not edit.
class BinaryTree {
public:
	int value;
	BinaryTree* left = nullptr;
	BinaryTree* right = nullptr;
	BinaryTree* parent = nullptr;

	BinaryTree(int value) { this->value = value; }
};

void inOrderTraverse(BinaryTree* node, vector<BinaryTree*>& array);

BinaryTree* findSuccessor(BinaryTree* tree, BinaryTree* node) {
	vector<BinaryTree*> orderedNodes;
	inOrderTraverse(tree, orderedNodes);

	for (int i = 0; i < orderedNodes.size(); i++) {
		auto currentNode = orderedNodes[i];

		if (currentNode != node) {
			continue;
		}

		if (i == orderedNodes.size() - 1) {
			return nullptr;
		}
		return orderedNodes[i + 1];
	}
	return nullptr;
}

void inOrderTraverse(BinaryTree* node, vector<BinaryTree*>& array) {
	if (node == nullptr)
	{
		return;
	}
	inOrderTraverse(node->left, array);
	array.push_back(node);
	inOrderTraverse(node->right, array);
}