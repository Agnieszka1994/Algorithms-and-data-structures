#include <vector>
#include <stack>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left = NULL;
  BinaryTree *right = NULL;

  BinaryTree(int value);
};

stack<BinaryTree*> inOrderTraverse(BinaryTree* tree, stack<BinaryTree*>& stack);

BinaryTree* flattenBinaryTree(BinaryTree* root) {
	stack<BinaryTree*> stack{};
	stack = inOrderTraverse(root, stack);
	BinaryTree* previousNode = nullptr;
	BinaryTree* nodeToModify = stack.top();

	while (!stack.empty()) {

		nodeToModify = stack.top();
		stack.pop();
		nodeToModify->left = !stack.empty() ? stack.top(): nullptr;
		nodeToModify->right = previousNode;
		previousNode = nodeToModify;
	}

		return nodeToModify;
}

stack<BinaryTree*> inOrderTraverse(BinaryTree* tree, stack<BinaryTree*> & stack) {
	if (tree->left != NULL)
	{
		stack = inOrderTraverse(tree->left, stack);
	}
	stack.push(tree);
	if (tree->right != NULL)
	{
		stack = inOrderTraverse(tree->right, stack);
	}

	return stack;
}