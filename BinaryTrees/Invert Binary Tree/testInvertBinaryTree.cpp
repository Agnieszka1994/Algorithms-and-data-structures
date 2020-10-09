#include "pch.h"
#include "InvertBinaryTree.cpp"
#include <vector>
#include <deque>

BinaryTree::BinaryTree(int value) {
    this->value = value;
    this->left = NULL;
    this->right = NULL;
}

void BinaryTree::insert(vector<int> values, int i) {
    if (i >= values.size()) {
        return;
    }
    deque<BinaryTree*> queue;
    queue.push_back(this);
    while (queue.size() > 0) {
        BinaryTree* current = queue.front();
        queue.pop_front();
        if (current->left == NULL) {
            current->left = new BinaryTree(values[i]);
            break;
        }
        queue.push_back(current->left);
        if (current->right == NULL) {
            current->right = new BinaryTree(values[i]);
            break;
        }
        queue.push_back(current->right);
    }
    this->insert(values, i + 1);
}

void BinaryTree::invertedInsert(vector<int> values, int i) {
    if (i >= values.size()) {
        return;
    }
    deque<BinaryTree*> queue;
    queue.push_back(this);
    while (queue.size() > 0) {
        BinaryTree* current = queue.front();
        queue.pop_front();
        if (current->right == NULL) {
            current->right = new BinaryTree(values[i]);
            break;
        }
        queue.push_back(current->right);
        if (current->left == NULL) {
            current->left = new BinaryTree(values[i]);
            break;
        }
        queue.push_back(current->left);
    }
    this->invertedInsert(values, i + 1);
}

bool compareBT(BinaryTree* a, BinaryTree* b) {
    if (a == NULL && b == NULL) {
        return true;
    }
    if (a != NULL && b != NULL) {
        return a->value == b->value && compareBT(a->left, b->left) &&
            compareBT(a->right, b->right);
    }
    return false;
}

TEST(SampleTestCase, SampleTest) {
    BinaryTree tree(1);
    tree.insert({ 2, 3, 4, 5, 6, 7, 8, 9 });
    invertBinaryTree(&tree);
    BinaryTree invertedTree(1);
    invertedTree.invertedInsert({ 2, 3, 4, 5, 6, 7, 8, 9 });
    assert(compareBT(&tree, &invertedTree) == 1);
}
