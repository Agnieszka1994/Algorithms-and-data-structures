#include <vector>
using namespace std;

vector<int> buildRightSubTree(vector<int> array);
vector<int> buildLeftSubTree(vector<int> array);

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {

	if (arrayOne.size() != arrayTwo.size())
		return false;
	if (arrayOne.size() == 0 && arrayTwo.size() == 0)
		return true;
	if (arrayOne[0] != arrayTwo[0]) {
		return false;
	}

	vector<int> leftSubTreeOne = buildLeftSubTree(arrayOne);
	vector<int> leftSubTreeTwo = buildLeftSubTree(arrayTwo);
	vector<int> rightSubTreeOne = buildRightSubTree(arrayOne);
	vector<int> rightSubTreeTwo = buildRightSubTree(arrayTwo);

	return sameBsts(rightSubTreeOne, rightSubTreeTwo) && sameBsts(leftSubTreeOne, leftSubTreeTwo);
}

vector<int> buildRightSubTree(vector<int> array) {
	vector<int> rightSubTree = {};
	for (int i = 1; i < array.size(); i++) {
		if (array[i] >= array[0])
			rightSubTree.push_back(array[i]);
	}
	return rightSubTree;
}
vector<int> buildLeftSubTree(vector<int> array) {
	vector<int> leftSubTree = {};
	for (int i = 1; i < array.size(); i++) {
		if (array[i] < array[0])
			leftSubTree.push_back(array[i]);
	}
	return leftSubTree;
}