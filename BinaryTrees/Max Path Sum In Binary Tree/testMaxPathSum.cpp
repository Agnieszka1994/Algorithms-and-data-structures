#include "pch.h"
#include "MaxPathSum.cpp"
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

TEST(SampleTestCase, SampleTest) {
    BinaryTree test(1);
    test.insert({ 2, 3, 4, 5, 6, 7 });
    assert(maxPathSum(test) == 18);
}
