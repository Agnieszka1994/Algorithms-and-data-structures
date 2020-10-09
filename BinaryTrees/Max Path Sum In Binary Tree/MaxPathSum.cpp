#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};
vector<int> maxSum(BinaryTree *tree);

int maxPathSum(BinaryTree tree) {

		vector<int> solution = maxSum(&tree);
		return solution[1];
}


vector<int> maxSum(BinaryTree *tree) { 

	/* returns two values:
	 max path sum as a branch 
	and running max path sum*/
	if (tree == nullptr) {
		return vector<int>{0, INT_MIN};
	}
	vector<int> leftMaxSums = maxSum(tree->left);
	vector<int> rightMaxSums = maxSum(tree->right);
	//this could be a negative:
	int maxChildSumAsBranch = max(leftMaxSums[0], rightMaxSums[0]);
	int currentValue = tree->value; 

	int maxPathSumAsBranch = max(maxChildSumAsBranch + currentValue, currentValue);
	int maxSumAsTriangle = max(leftMaxSums[0] + rightMaxSums[0] + currentValue, maxPathSumAsBranch);
	int runningMaxPathSum = max(leftMaxSums[1], max(maxSumAsTriangle, rightMaxSums[1]));
	
	return { maxPathSumAsBranch, runningMaxPathSum };
} 