#include "pch.h"
#include <deque>
#include "findSuccessor.cpp"
 
TEST(SampleTestCase1, SampleTest) {
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->left->parent = root;
    root->right = new BinaryTree(3);
    root->right->parent = root;
    root->left->left = new BinaryTree(4);
    root->left->left->parent = root->left;
    root->left->right = new BinaryTree(5);
    root->left->right->parent = root->left;
    root->left->left->left = new BinaryTree(6);
    root->left->left->left->parent = root->left->left;
    auto node = root->left->right;
    auto expected = root;
    auto actual = findSuccessor(root, node);
    assert(expected == actual);
};