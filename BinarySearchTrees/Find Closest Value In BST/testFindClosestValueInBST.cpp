#include "pch.h"
#include "FindClosestValueInBST.cpp"

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
    root->right->left = new BST(13);
    root->right->left->right = new BST(14);
    root->right->right = new BST(22);
    int expected = 13;
    int actual = findClosestValueInBst(root, 12);
    assert(expected == actual);
};
