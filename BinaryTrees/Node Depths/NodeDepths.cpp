using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};
void calculateTreeDepth(BinaryTree* node, int currentDepth, int& totalDepth);

int nodeDepths(BinaryTree* root) {
	int depth = 0;
	calculateTreeDepth(root, 0, depth);
	return depth;
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
