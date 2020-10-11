#include <vector>
using namespace std;

class SpecialBST {
public:
	int value;
	int index;
	int smallerCountAtInsert;
	int leftSubtreeSize{ 0 };
	SpecialBST* left{ nullptr };
	SpecialBST* right{ nullptr };

	SpecialBST(int value, int index, int smallerCountAtInsert) :
		value(value), index(index), smallerCountAtInsert(smallerCountAtInsert) {}

	void insert(int value, int index, int smallerCountAtInsert = 0) {
		if (value < this->value) {
			leftSubtreeSize++;
			if (left == nullptr) {
				left = new SpecialBST(value, index, smallerCountAtInsert);
			}
			else {
				left->insert(value, index, smallerCountAtInsert);
			}
		}
		else {
			smallerCountAtInsert += leftSubtreeSize;
			if (value > this->value) {
				smallerCountAtInsert++;
			}
			if (right == nullptr) {
				right = new SpecialBST(value, index, smallerCountAtInsert);
			}
			else {
				right->insert(value, index, smallerCountAtInsert);
			}
		}
	}
};

void getRightSmaller(SpecialBST*, vector<int>&);

vector<int> rightSmallerThan(vector<int> array) {
	if (array.size() == 0) {
		return {};
	}
	int lastIdx = array.size() - 1;
	SpecialBST* tree = new SpecialBST(array[lastIdx], lastIdx, 0);
	for (int idx = array.size() - 2; idx >= 0; idx--) {
		tree->insert(array[idx], idx);
	}
	vector<int> rightSmaller = array;
	getRightSmaller(tree, rightSmaller);
	return rightSmaller;
}

void getRightSmaller(SpecialBST* tree, vector<int>& rightSmaller) {
	if (tree == nullptr)
		return;
	rightSmaller[tree->index] = tree->smallerCountAtInsert;
	getRightSmaller(tree->left, rightSmaller);
	getRightSmaller(tree->right, rightSmaller);
}