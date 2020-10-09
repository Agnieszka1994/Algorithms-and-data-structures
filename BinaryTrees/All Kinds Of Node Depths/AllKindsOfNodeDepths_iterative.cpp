using namespace std;

class BinaryTree {
public:
	int value;
	BinaryTree* left;
	BinaryTree* right;

	BinaryTree(int value) {
		this->value = value;
		left = nullptr;
		right = nullptr;
	}
};

class TreeInfo {
public:
	int numNodesInTree;
	int sumOfDepths;
	int sumOfAllDepths;
};

TreeInfo getAllDepths(BinaryTree* root);

int allKindsOfNodeDepths(BinaryTree* root) {
	TreeInfo treeInfo = getAllDepths(root);

	return treeInfo.sumOfAllDepths;
}

TreeInfo getAllDepths(BinaryTree* node) {
	if (node == nullptr)
		return TreeInfo{ 0,0,0 };

 

	TreeInfo leftInfo = getAllDepths(node->left);
	TreeInfo rightInfo = getAllDepths(node->right);

	int sumOfLeftDepths = leftInfo.sumOfDepths + leftInfo.numNodesInTree;
	int sumOfRightDepths = rightInfo.sumOfDepths + rightInfo.numNodesInTree;

	int numNodesInTree = 1 + leftInfo.numNodesInTree + rightInfo.numNodesInTree;
	int sumOfDepths = sumOfLeftDepths + sumOfRightDepths;
	int sumOfAllDepths = sumOfDepths+ leftInfo.sumOfAllDepths + rightInfo.sumOfAllDepths; ;

	return TreeInfo{ numNodesInTree , sumOfDepths, sumOfAllDepths };
}