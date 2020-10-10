#include "pch.h"
#include "BSTTraversal.cpp"

BST::BST(int val) {
    value = val;
    left = NULL;
    right = NULL;
}

TEST(SampleTestCase_1, SampleTest) {
    BST* root = new BST(10);
    root->left = new BST(5);
    root->left->left = new BST(2);
    root->left->left->left = new BST(1);
    root->left->right = new BST(5);
    root->right = new BST(15);
    root->right->right = new BST(22);

    vector<int> inOrder{ 1, 2, 5, 5, 10, 15, 22 };
    vector<int> preOrder{ 10, 5, 2, 1, 5, 15, 22 };
    vector<int> postOrder{ 1, 2, 5, 5, 22, 15, 10 };
    assert(inOrderTraverse(root, {}) == inOrder);
    assert(preOrderTraverse(root, {}) == preOrder);
    assert(postOrderTraverse(root, {}) == postOrder);
};
