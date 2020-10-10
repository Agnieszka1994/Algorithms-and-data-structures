#include <climits>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};
bool validateHelper(BST *tree, int, int);
bool validateBst(BST *tree) {
	
	//if(tree == NULL) return false;
 return validateHelper(tree, INT_MIN, INT_MAX);
}

bool validateHelper(BST *tree, int minVal, int maxVal){
	BST *currentNode = tree; 
	if(tree == NULL) {
		return true;
	}
	if(currentNode->value < minVal || currentNode->value >= maxVal){
		return false;
	}
	else{
			bool leftIsValid = validateHelper(currentNode->left, minVal, currentNode->value);
			bool rightIsValid = validateHelper(currentNode->right, currentNode->value, maxVal);
		if(leftIsValid && rightIsValid){
			return true;
		}
		else return false;
	}
	
	return true;
}