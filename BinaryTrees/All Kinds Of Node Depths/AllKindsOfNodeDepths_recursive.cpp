using namespace std;

class BinaryTree {
public:
	int value;
	BinaryTree* left;
	BinaryTree* right;

	BinaryTree(int value) {
		this->value = value;
		left = NULL;
		right = NULL;
	}
};
void calculateTreeDepth(BinaryTree* node, int currentDepth, int& totalDepth);
void nodeDepths(BinaryTree* root, int& totalDepth);

int allKindsOfNodeDepths(BinaryTree* root) {
	int depth = 0;
	nodeDepths(root, depth);
	return depth;
}



void nodeDepths(BinaryTree* root, int& totalDepth) {
	calculateTreeDepth(root, 0, totalDepth);
	if (root->left != NULL) {
		nodeDepths(root->left, totalDepth) ;
	}
	if (root->right != NULL) {
		nodeDepths(root->right, totalDepth) ;
	}
	return;
}
void calculateTreeDepth(BinaryTree* node, int currentDepth, int& totalDepth) {
	if (node == NULL) {
		return;
	}
	int current = currentDepth + 1;
	totalDepth += currentDepth;

	if (node->right == NULL && node->left == NULL) {
		return;
	}
	calculateTreeDepth(node->right, current, totalDepth);
	calculateTreeDepth(node->left, current, totalDepth);
}
