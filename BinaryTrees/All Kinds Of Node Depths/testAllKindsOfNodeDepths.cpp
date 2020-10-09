#include "pch.h"
#include "AllKindsOfNodeDepths_iterative.cpp"
#include <vector>

TEST(SampleTestCase, SampleTest) {
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->left->left = new BinaryTree(4);
    root->left->left->left = new BinaryTree(8);
    root->left->left->right = new BinaryTree(9);
    root->left->right = new BinaryTree(5);
    root->right = new BinaryTree(3);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);
    int actual = allKindsOfNodeDepths(root);
    assert(actual == 26);
}

