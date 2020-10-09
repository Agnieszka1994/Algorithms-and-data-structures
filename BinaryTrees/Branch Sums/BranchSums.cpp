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

void branchSum(BinaryTree* node, int currentSum, vector<int> &sums);

vector<int> branchSums(BinaryTree* root) {
	vector<int> sums;

	branchSum(root, 0, sums);
	return sums;
}

void branchSum(BinaryTree* node, int currentSum, vector<int> &sums) {
		if (node == NULL) {
		return;
	}
	
	int newSum = currentSum + node->value;
	if (node->left == NULL && node->right == NULL) {
		sums.push_back(newSum);
		return;
	}
	
	branchSum(node->left, newSum, sums);
	branchSum(node->right, newSum, sums);
}

