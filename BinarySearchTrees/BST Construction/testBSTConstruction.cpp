#include "pch.h"
#include "BSTConstruction.cpp"

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

    root->insert(12);
    assert(root->right->left->left->value == 12);

    root->remove(10);
    assert(root->contains(10) == false);
    assert(root->value == 12);

    assert(root->contains(15));
};
