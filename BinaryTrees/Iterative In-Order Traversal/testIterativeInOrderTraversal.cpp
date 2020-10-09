#include "pch.h"
#include "IterativeInOrderTraversal.cpp"
#include <vector>
#include <deque>

BinaryTree::BinaryTree(int value, BinaryTree* parent) {
    this->value = value;
    this->left = NULL;
    this->right = NULL;
    this->parent = parent;
}

vector<int> testArray = {};

void testCallback(BinaryTree* tree) {
    if (tree == NULL) {
        return;
    }
    testArray.push_back(tree->value);
}

TEST(SampleTestCase, SampleTest) {
    BinaryTree* root = new BinaryTree(1, NULL);
    root->left = new BinaryTree(2, root);
    root->left->left = new BinaryTree(4, root->left);
    root->left->left->right = new BinaryTree(9, root->left->left);
    root->right = new BinaryTree(3, root);
    root->right->left = new BinaryTree(6, root->right);
    root->right->right = new BinaryTree(7, root->right);

    testArray = {};
    iterativeInOrderTraversal(root, &testCallback);
    vector<int> expected{ 4, 9, 2, 1, 6, 3, 7 };
    assert(testArray == expected);
}
