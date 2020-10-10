#include <cmath>
class BST {
public:
	int value;
	BST *left;
	BST *right;

	BST(int val);
	BST &insert(int val);
};

int findClosestValueInBst(BST* tree, int target) {
	int closest = tree->value;
	BST* currentNode = tree;
	while (currentNode != NULL) {

		if (abs(target - currentNode->value) < abs(target - closest)) {
			closest = currentNode->value;
		}
		if (target < currentNode->value) {
			currentNode = currentNode->left;
		}
		else if(target > currentNode->value) {
			currentNode = currentNode->right;
		}
		else break;

	}
	return closest;
}