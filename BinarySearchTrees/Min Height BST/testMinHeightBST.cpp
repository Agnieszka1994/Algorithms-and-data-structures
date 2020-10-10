#include "pch.h"
#include "MinHeightBST.cpp"

bool validateBstHelper(BST* tree, int minValue, int maxValue) {
    if (tree->value < minValue || tree->value >= maxValue) {
        return false;
    }
    if (tree->left != NULL &&
        !validateBstHelper(tree->left, minValue, tree->value)) {
        return false;
    }
    if (tree->right != NULL &&
        !validateBstHelper(tree->right, tree->value, maxValue)) {
        return false;
    }
    return true;
}

vector<int> inOrderTraverse(BST* tree, vector<int> array) {
    if (tree->left != NULL) {
        array = inOrderTraverse(tree->left, array);
    }
    array.push_back(tree->value);
    if (tree->right != NULL) {
        array = inOrderTraverse(tree->right, array);
    }
    return array;
}

bool validateBst(BST* tree) {
    return validateBstHelper(tree, INT_MIN, INT_MAX);
}

template <class BST> int getTreeHeight(BST* tree, int height) {
    if (tree == NULL)
        return height;
    int leftTreeHeight = getTreeHeight(tree->left, height + 1);
    int rightTreeHeight = getTreeHeight(tree->right, height + 1);
    return max(leftTreeHeight, rightTreeHeight);
}

TEST(SampleTestCase_1, SampleTest) {
    vector<int> array{ 1, 2, 5, 7, 10, 13, 14, 15, 22 };
    auto tree = minHeightBst(array);

    assert(validateBst(tree));
    assert(getTreeHeight(tree, 0) == 4);

    auto inOrder = inOrderTraverse(tree, {});
    vector<int> expected{ 1, 2, 5, 7, 10, 13, 14, 15, 22 };
    assert(inOrder == expected);
};
